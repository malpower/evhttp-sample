#include "main.h"
#include "route-handler.h"


#ifndef __PATH_HANDLER_HPP__
#define __PATH_HANDLER_HPP__

class PathHandler: public RouteHandler
{
public:
    PathHandler(const std::string path,const evhttp_cmd_type &method);
    virtual bool match(const std::string &path,const evhttp_cmd_type &method) const;
    virtual void process(Request &request) const =0;
protected:
    std::string attachTo;
    evhttp_cmd_type acceptedMethod;
};

#endif