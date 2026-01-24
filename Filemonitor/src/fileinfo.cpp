#include "../include/fileinfo.h"
namespace fs = std::filesystem;
Fileinfo::Fileinfo(){}

Fileinfo::Fileinfo(int cpp, int h, std::string t, long long l) : cpp_count(cpp), h_count(h), timestamp(t), lines(l) {};

int Fileinfo::total_checks = 0;

void Fileinfo::update(const std::string& path){
    //1)Подсчет файлов и строк в них
    cpp_count=0;
    h_count=0;
    lines=0;
    if(!fs::exists(path) || !fs::is_directory(path)){
        std::cerr<<"Ошибка передачи пути, попробуйте еще раз\n";
        return;
    }
    for(const fs::directory_entry & dir : fs::recursive_directory_iterator(path)){
        if (!dir.is_regular_file()) continue;
        if(dir.path().extension() == ".cpp"){
            std::ifstream f(dir.path());
            cpp_count++;
            if(!f.is_open()){
                std::cerr<<"Ошибка открытия файла!\n";
                continue;
            }
            std::string lin;
            while(std::getline(f,lin)){
                lines++;
            }
        }else if(dir.path().extension() == ".h"){
            std::ifstream f(dir.path());
            h_count++;
            if(!f.is_open()){
                std::cerr<<"Ошибка открытия файла!\n";
                continue;
            }
            std::string l;
            while(std::getline(f,l)){
                lines++;
            }
        }
    }
    //2)Время
    auto n = std::chrono::system_clock::now();
    time_t ot = std::chrono::system_clock::to_time_t(n);
    std::stringstream s;
    s << std::put_time(std::localtime(&ot), "%Y-%m-%d %H:%M:%S");
    timestamp=s.str();
    //3)Подсчет проверок
    total_checks++;
}

void Fileinfo::Get() const{
    std::cout<<"Кол-во |*.h файлов| : " << h_count <<'\n';
    std::cout<<"Кол-во |*.сpp файлов| : " << cpp_count <<'\n';
    std::cout<<"Кол-во строк во всех файлах : " << lines <<'\n';
    std::cout<<"Время изменения файлов : " << timestamp <<'\n';
}

void Fileinfo::GetCheck(){
    std::cout<<"Кол-во проверко: "<< total_checks <<"\n";
}

int Fileinfo::getCppCount() const { return cpp_count; }
int Fileinfo::getHCount() const { return h_count; }
long long Fileinfo::getLines() const { return lines; }

