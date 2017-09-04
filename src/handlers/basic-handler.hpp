#include "../main.h"
#include "../path-handler.h"


#ifndef __BASIC_HANDLER_HPP__
#define __BASIC_HANDLER_HPP__

class BasicHandler: public PathHandler
{
public:
    BasicHandler():PathHandler("/",evhttp_cmd_type::EVHTTP_REQ_GET){};
    void virtual process(Request &request) const
    {
        request.setHeader("Content-Type","text/html;charset=UTF-8");
        request.end("<h1>H1 Here</h1><a href=\"/ok\">HERE</a><form action=\"/ok\" method=\"POST\"><input type=\"text\" name=\"sdf\" /><button type=\"submit\">OK</button></form>");
    };
};

#endif


