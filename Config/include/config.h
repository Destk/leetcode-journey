#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
    class Config{
        private:
            std::string filename{};
            std::unordered_map<std::string,std::string> data{};
        public:
            Config(const std::string& filename);
            std::string get(const std::string& key) const;
            bool exists(const std::string& key) const;

            ~Config();
        };   

#endif //CONFIG_H