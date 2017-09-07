#include "path-handler.h"


PathHandler::PathHandler(const std::string path,const evhttp_cmd_type &method):
attachTo(path),acceptedMethod(method){}




bool PathHandler::match(const std::string &path,const evhttp_cmd_type &method) const
{
    std::regex r("\\{[^}{]{1,}\\}");
    std::string xp=std::regex_replace(attachTo,r,"[^/]*");
    r=std::regex(xp);
    if (std::regex_match(path,r) && method==acceptedMethod)
    {
        return true;
    }
    return false;
}


std::map<std::string,std::string> PathHandler::getUrlParameters(const Request &request) const
{
    std::map<std::string,std::string> res;
    std::regex r("\\{[^/{}]{1,}\\}");
    std::vector<std::string> names;
    for (std::sregex_token_iterator it(attachTo.cbegin(),attachTo.cend(),r),end;it!=end;it++)
    {
        names.push_back(*it);
    }
    std::string path=std::regex_replace(attachTo,r,"([^/]*)");
    std::regex r2(path);
    if (r2.mark_count()==0)
    {
        return res;
    }
    std::ostringstream mt;
    for (int i=0;i<r2.mark_count();i++)
    {
        mt<<"|$"<<(i+1);
    }
    std::string output=std::regex_replace(request.getPath(),r2,mt.str().substr(1));
    std::vector<std::string> values=splitString(output,'|');
    for (int i=0;i<names.size();i++)
    {
        res[names[i].substr(1,names[i].length()-2)]=values[i];
    }
    return res;
}

std::vector<std::string> PathHandler::splitString(const std::string &src,const char s) const
{
    std::vector<std::string> v;
    int p=0;
    for (int i=0;i<src.length();i++)
    {
        if (src.at(i)==s)
        {
            v.push_back(src.substr(p,i-p));
            p=i+1;
        }
    }
    if (p<src.length())
    {
        v.push_back(src.substr(p,src.length()-p));
    }
    return v;
}