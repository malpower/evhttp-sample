#include "main.h"
#include "router.h"
#include "handlers/basic-handler.hpp"
#include "handlers/second-handler.hpp"
#include "handlers/post-handler.hpp"
#include "handlers/url-handler.hpp"

#ifndef __SERVICE_HPP__
#define __SERVICE_HPP__
class Service
{
public:
    static void init()
    {
        Router::addHandler(new BasicHandler);
        Router::addHandler(new SecondHandler);
        Router::addHandler(new PostHandler);
        Router::addHandler(new UrlHandler);
    }
};

#endif


