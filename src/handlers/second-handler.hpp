#include "../main.h"
#include "../path-handler.h"


#ifndef __SECOND_HANDLER_HPP__
#define __SECOND_HANDLER_HPP__

class SecondHandler: public PathHandler
{
public:
    SecondHandler():PathHandler("/ok",evhttp_cmd_type::EVHTTP_REQ_GET){};
    void virtual process(Request &request) const
    {
        request.setHeader("Content-Type","text/html;charset=UTF-8");
        request.end("<h1>Second</h1>");
    };
};

#endif