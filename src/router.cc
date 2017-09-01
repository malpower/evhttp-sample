#include "router.h"

std::vector<const RouteHandler*> Router::handlers;


void Router::addHandler(const RouteHandler *handler)
{
    handlers.push_back(handler);
}



void Router::handle(const char *path,Request &request)
{
    std::string p=path;
    std::vector<const RouteHandler*>::iterator it;
    for (it=handlers.begin();it!=handlers.end();it++)
    {
        if ((*it)->match(p,request.method()))
        {
            (*it)->process(request);
            return;
        }
    }
    give404(request);
}


void Router::give404(Request &request)
{
    request.setHeader("Content-Type","text/html;charset=UTF-8");
    request.end("<h1>404 NOT FOUND</h1>",404,"NOT FOUND");
}


