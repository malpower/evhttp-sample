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
    virtual std::map<std::string,std::string> getUrlParameters(const Request &request) const;
    std::string attachTo;
    evhttp_cmd_type acceptedMethod;
private:
    std::vector<std::string> splitString(const std::string &src,const char s) const;
};

#endif