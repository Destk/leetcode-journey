#include <iostream>
#include <curl/curl.h>
#include <string>
//#include <nlohmann/json.hpp>

size_t WriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata) {
    std::size_t bytes = size * nmemb;
    auto* data = static_cast<std::string*>(userdata);
    data->append(ptr, bytes);  
    return bytes;
}


std::string httpGet(const std::string& url){
    CURL* handle = curl_easy_init();
    if(handle == nullptr){
        throw std::runtime_error("curr init ERROR");
    }
    std::string response;
    curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION,WriteCallback);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);
    CURLcode res = curl_easy_perform(handle);
    if(res != CURLE_OK){
        curl_easy_cleanup(handle);
        throw std::runtime_error(curl_easy_strerror(res));
    }
    curl_easy_cleanup(handle);
    return response;
}

int main(){
    try{
        std::string body = httpGet("https://httpbin.org/json");
        std::cout<< body <<'\n';
    }catch(const std::exception& e){
        std::cerr <<"ERROR: "<< e.what()<<'\n';
    }
    return 0;
}