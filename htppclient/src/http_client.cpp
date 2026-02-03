#include "../include/http_client.h"
#include <iostream>
#include <fstream>
HttpClient::HttpClient() : curl(nullptr), headers(nullptr){
    curl = curl_easy_init();
}
HttpClient::~HttpClient(){
    if (headers) {
        curl_slist_free_all(headers);
        headers = nullptr;
    }
    if (curl) {
        curl_easy_cleanup(curl);
        curl = nullptr;
    }
}   

void HttpClient::SetHeader(const std::string& name, const std::string& value){
    std::string line = name + ": " + value;
    headers = curl_slist_append(headers, line.c_str());
}

std::string HttpClient::Get(const std::string& url){
     if (!curl) return "";
    response_data.clear();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    CURLcode res = curl_easy_perform(curl);
    if( res != CURLE_OK){
        std::cerr<<"curl_easy_perform() failed: "<<curl_easy_strerror(res)<<'\n';
    }
    return response_data;
}
std::string HttpClient::Post(const std::string& url, const std::string& data){
    if(!curl) return "";
    response_data.clear();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl,CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    CURLcode res = curl_easy_perform(curl);
    if( res != CURLE_OK){
        std::cerr<<"curl_easy_perform() failed: "<<curl_easy_strerror(res)<<'\n';
    }
    return response_data;    
}
bool HttpClient::SaveToFile(const std::string& filename){
    std::ofstream out;
    out.open(filename);
    if(!out.is_open()){
        return false;
    }
    out << response_data;
    out.close();
    return true;
}

json HttpClient::GetJson(const std::string& url){
    std::string response = Get(url);
    if(response.empty()){
        throw std::runtime_error("Empty HTTP response");
    }
    try{
        json j = json::parse(response);
        return j;
    }catch(json::parse_error& e){
        throw std::runtime_error(std::string("JSON parse error: ") + e.what());
    }
}