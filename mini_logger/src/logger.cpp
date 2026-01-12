#include <iostream>
#include "../include/logger.h"

logger::logger(const std::string& filename){
    file.open(filename);
};

void logger::log(const std::string& message, const std::string& lvl){
    file << "[ " << message << " - " << lvl << " ]\n";
}

logger::~logger(){
    file.close();
};