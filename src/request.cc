#include "request.h"


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