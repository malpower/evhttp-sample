#include "path-handler.h"


PathHandler::PathHandler(const std::string path,const evhttp_cmd_type &method):
attachTo(path),acceptedMethod(method){}




bool PathHandler::match(const std::string &path,const evhttp_cmd_type &method) const
{
    if (path==attachTo && method==acceptedMethod)
    {
        return true;
    }
    return false;
}


