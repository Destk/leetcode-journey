#include "../include/config.h"

Config::Config(const std::string& filename){
    this->filename = filename;
    std::ifstream file(filename);
    std::string line;
    if(file.is_open()){
        while(std::getline(file,line)){
            std::cout<<line<<'\n';
            size_t pos = line.find("=");
            std::string key = line.substr(0, pos);
            std::string val = line.substr(pos+1);
            data[key] = val;
        }
    }else{
        std::cerr<<"Error Open File\n";
        return ;
    }   
    file.close();
}

std::string Config::get(const std::string& key) const{
    if(data.count(key)){
        return data.at(key);
    }
    return "";
}

bool Config::exists(const std::string& key) const{
    if(data.count(key)){
        return true;
    }
    return false;
}

Config::~Config(){
    std::cout << "Config destroyed (file: " << filename << ")" << std::endl;
}