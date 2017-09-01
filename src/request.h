#include "main.h"

#ifndef __REQUEST_H__

#define __REQUEST_H__



class Request
{
public:
    Request(evhttp_request *req);
    void virtual end(const char *content,unsigned int status,const char *statusText);
    void virtual end(const char *content,unsigned int status);
    void virtual end(const char *content);
    void virtual setHeader(const char *name,const char *content);
    evhttp_cmd_type virtual method();
    evbuffer virtual *getBody();
private:
    evhttp_request *request;
};
#endif
