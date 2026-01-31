#ifndef HTTP_CL
#define HTTP_CL

#include <curl/curl.h>
#include <string>
class HttpClient{
    private:
    std::string response_data{};
    struct curl_slist* headers;
    CURL* curl;
    static size_t WriteCallback(void *ptr, size_t size, size_t nmemb, void *data){
        auto bytes = size*nmemb;
        auto* d = static_cast<std::string*>(data);
        d->append(static_cast<char*>(ptr),bytes);
        return bytes;
    }
    public:
        HttpClient();
        void SetHeader(const std::string& name, const std::string& value);
        std::string Get(const std::string& url);
        std::string Post(const std::string& url, const std::string& data);
        bool SaveToFile(const std::string& filename);
        ~HttpClient();

};
#endif //HTTP_CL