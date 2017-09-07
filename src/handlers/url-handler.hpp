#include "../main.h"
#include "../path-handler.h"


#ifndef __URL_HANDLER_HPP__
#define __URL_HANDLER_HPP__

class UrlHandler: public PathHandler
{
public:
    UrlHandler():PathHandler("/malpower/{pok}-uuu-{jjj}/ooo/{yyy}",evhttp_cmd_type::EVHTTP_REQ_GET){};
    void virtual process(Request &request) const
    {
        std::map<std::string,std::string> p=getUrlParameters(request);
        request.setHeader("Content-Type","text/html;charset=UTF-8");
        std::string content="<h1>Here i am</h1><br />";
        content+="pok: "+p["pok"]+"<br />";
        content+="yyy: "+p["yyy"]+"<br />";
        content+="jjj: "+p["jjj"]+"<br />";
        request.end(content.c_str());
    };
};

#endif

