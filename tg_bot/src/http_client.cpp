#include "../include/http_client.h"

HttpClient::HttpClient(){
    curl_global_init(CURL_GLOBAL_ALL);
    headers = NULL;
    curl = curl_easy_init();
    if(!curl){
        throw std::runtime_error("Failed to initialize CURL");
    }
}

std::string HttpClient::Get(const std::string& url){
    std::string response{};
    if(headers){
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writecallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode handle = curl_easy_perform(curl);
    if(handle != CURLE_OK){
        throw std::runtime_error("Failed to CURL Get-perform");
    }
    ClearHeaders();
    return response;
}

std::string HttpClient::Post(const std::string& url, const std::string& d){
    std::string response{};
    if(headers){
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writecallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, d.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, d.size());

    CURLcode handle = curl_easy_perform(curl);
    if(handle != CURLE_OK){
        throw std::runtime_error("Failed to CURL Post-perform");
    }
    ClearHeaders();
    return response;
}

void HttpClient::SetHeaders(const std::string& name, const std::string& val){
    std::string header_line = name + ": " + val;
    headers = curl_slist_append(headers, header_line.c_str());
}
void HttpClient::ClearHeaders(){
    if(headers){
        curl_slist_free_all(headers);
        headers = nullptr;
    }
}
json HttpClient::GetJson(const std::string& url){
    std::string fj = Get(url);
    json j = json::parse(fj);
    ClearHeaders();
    return j;
}

HttpClient::~HttpClient(){
    curl_global_cleanup();
    if(curl){
        curl_easy_cleanup(curl);
    }
}