#include "../main.h"
#include "../path-handler.h"


#ifndef __POST_HANDLER_HPP__
#define __POST_HANDLER_HPP__

class PostHandler: public PathHandler
{
public:
    PostHandler():PathHandler("/ok",evhttp_cmd_type::EVHTTP_REQ_POST){};
    void virtual process(Request &request) const
    {
        evbuffer *body=request.getBody();
        unsigned long size=evbuffer_get_length(body);
        char *mem=new char[size+1];
        mem[size]=0;
        evbuffer_copyout(body,mem,size);
        request.setHeader("Content-Type","text/html;charset=UTF-8");
        std::string a="<h1>JJJJJJJJ";
        a+=mem;
        a+="</h1>";
        request.end(a.c_str());
        delete[] mem;
    };
};

#endif