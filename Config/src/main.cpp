#include "../include/config.h"

int main(){
    Config cfg("test.conf");
    if(cfg.exists("database_host")){
        std::cout<<"Host - "<< cfg.get("database_host")<<'\n';
    }
    if(cfg.exists("database_port")){
        std::cout<<"Port - "<< cfg.get("database_port") <<'\n';
    }
    if(cfg.exists("debug_mode")){
        std::cout<<"Mode - "<< cfg.get("debug_mode")<<'\n';
    }
    if(cfg.exists("log_level")){
        std::cout<<"Level - "<< cfg.get("log_level") << '\n';
    }
    return 0;
}