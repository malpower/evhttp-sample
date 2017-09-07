#include "request.h"


using namespace std;



Request::Request(evhttp_request *req):
request(req){}




void Request::end(const char *content,unsigned int status,const char *statusText)
{
    evbuffer *buffer=evbuffer_new();
    evbuffer_add_printf(buffer,"%s",content);
    evhttp_send_reply(request,status,statusText,buffer);
    evbuffer_free(buffer);
}
void Request::end(const char *content,unsigned int status)
{
    end(content,status,"OK");
}

void Request::end(const char *content)
{
    end(content,200,"OK");
}


void Request::setHeader(const char *name,const char *content)
{
    evhttp_add_header(evhttp_request_get_output_headers(request),name,content);
}

evhttp_cmd_type Request::method()
{
    return evhttp_request_get_command(request);
}

evbuffer *Request::getBody()
{
    return evhttp_request_get_input_buffer(request);
}

map<string,string> Request::getQuery()
{
    return splitParameters(evhttp_request_get_uri(request));
}

map<string,string> Request::getFormData()
{
    evbuffer *body=getBody();
    unsigned long size=evbuffer_get_length(body);
    char *mem=new char[size+1];
    mem[size]=0;
    evbuffer_copyout(body,mem,size);
    string src=mem;
    delete[] mem;
    return splitParameters(src);
}

map<string,string> Request::splitParameters(const string &src)
{
    map<string,string> params;
    string url=src;
    regex r("[^&=\?]*=[^&=]*");
    for (sregex_token_iterator it(url.cbegin(),url.cend(),r),end;it!=end;it++)
    {
        vector<string> v=splitString(*it,'=');
        params[v[0]]=v[1];
    }
    return params;
}

vector<string> Request::splitString(const string &src,const char s) const
{
    vector<string> v;
    int p=0;
    for (int i=0;i<src.length();i++)
    {
        if (src.at(i)==s)
        {
            v.push_back(src.substr(p,i-p));
            p=i+1;
        }
    }
    if (p<src.length())
    {
        v.push_back(src.substr(p,src.length()-p));
    }
    return v;
}
string Request::getPath() const
{
    vector<string> v=splitString(evhttp_request_get_uri(request),'?');
    return v[0];
}