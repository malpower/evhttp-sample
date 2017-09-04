#include "main.h"

#ifndef __REQUEST_H__

#define __REQUEST_H__



class Request
{
public:
    Request(evhttp_request *req);
    virtual void end(const char *content,unsigned int status,const char *statusText);
    virtual void end(const char *content,unsigned int status);
    virtual void end(const char *content);
    virtual void setHeader(const char *name,const char *content);
    virtual std::map<std::string,std::string> getParameters();
    evhttp_cmd_type virtual method();
    evbuffer virtual *getBody();
private:
    evhttp_request *request;
};
#endif