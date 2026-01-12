#include<iostream>
#include"../include/logger.h"

int main(){
    logger lg("log.h");
    lg.log("Programm start", "START");
    lg.log("Processing data", "DEBUG");
    lg.log("Error programm", "ERROR");
    return 0;
}