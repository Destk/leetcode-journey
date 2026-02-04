#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

class HttpClient{
    private:
        CURL* curl;
        static inline size_t writecallback(char* ptr, size_t size, size_t nmemb, void* data){
            size_t res = size*nmemb;
            std::string* resdata = static_cast<std::string*>(data);
            resdata->append(ptr,res);
            return res;
        }
        struct curl_slist* headers;
        
    public:
        HttpClient();
        std::string Get(const std::string& url);
        void SetHeaders(const std::string& name, const std::string& val);
        void ClearHeaders();
        json GetJson(const std::string& url);
        std::string Post(const std::string& url, const std::string& d);
        ~HttpClient();
};

#endif //HTTP_CLIENT_H