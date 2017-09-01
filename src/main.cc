#include "main.h"
#include "request.h"
#include "router.h"
#include "service.hpp"

using namespace std;


void dispatch(evhttp_request *request,void *arg)
{
    Request res(request);
    Router::handle(evhttp_request_get_uri(request),res);
}





int main(int argc,char *argv[])
{
    Service::init();
    event_base *base=event_base_new();
    evhttp *http=evhttp_new(base);
    evhttp_bind_socket(http,"0.0.0.0",3000);
    evhttp_set_gencb(http,dispatch,NULL);
    cout<<"Service started."<<endl;
    event_base_dispatch(base);
    return 0;
}


