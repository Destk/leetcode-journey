#include<iostream>
#include<string>
#include<limits>

std::string inp(){
    bool c = false;
    std::string s{};
    while(!c){
        std::cout<<"Введите строку символы\n(чтобы закончитть ввод нажмите Enter)\n";
        std::getline(std::cin,s);
        if(s.empty()){
            std::cout<<"Ошибка ввода, попробуйте еще раз\n";
            continue;
        }else{
            c = true;
        }
    }
    return s;
}

std::string removeDuplicates(std::string s) {
    std::string tmp{};
    for(size_t i = 0; i < s.size(); i++){
        if(!tmp.empty() && tmp.back() == s[i]){
            tmp.pop_back();
        }else{
            tmp.push_back(s[i]);
        }
    }
    return tmp;
}

void out(std::string& s){
    std::cout<<"Получившаяся строка: "<< s <<'\n';
}
int main(){
    char stop{};
    std::cout<<"Программа по удалению дубликатов\n";
    do{
        std::string s = inp();
        std::string r = removeDuplicates(s);
        out(r);
        std::cout<<"Продолжить?(y/n): ";
        std::cin>>stop;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(stop=='y'||stop=='Y');
    return 0;
}