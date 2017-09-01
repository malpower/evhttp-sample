#include "main.h"
#include "route-handler.h"
#include "request.h"

#ifndef __ROUTER_H__
#define __ROUTER_H__

class Router
{
public:
    static void addHandler(const RouteHandler *handler);
    static void handle(const char *path,Request &request);
private:
    static std::vector<const RouteHandler*> handlers;
    static void give404(Request &request);
};

#endif