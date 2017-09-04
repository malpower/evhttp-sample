#include "main.h"
#include "request.h"

#ifndef __ROUTE_HANDLER_H__
#define __ROUTE_HANDLER_H__

class RouteHandler
{
public:
    virtual void process(Request &request) const =0;
    virtual bool match(const std::string &path,const evhttp_cmd_type &method) const =0;
private:
    char *path;
};

#endif

