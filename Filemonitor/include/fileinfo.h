#ifndef FILEINFO_H
#define FILEINFO_H
#include <string>
#include <cstdint>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <locale>
#include <clocale> 
class Fileinfo{
    private:
        int cpp_count{};
        int h_count{};
        std::string timestamp{};
        long long lines{};
        static int total_checks;
    public:
        Fileinfo();
        Fileinfo(int cpp, int h, std::string t, long long l);
        void update(const std::string& path);
        void Get() const;
        static void GetCheck();

        int getCppCount() const;
        int getHCount() const;
        long long getLines() const;

};
#endif //FILEINFO_H