#include <iostream>
#include <string>
#include <cctype>

class Solution {
private:
    std::string s;
    int k;
    void error(){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
    }
public:
    void inp(){
        bool st{false};
        while(!st){
            std::cout<<"Введите строку из английски букв: ";
            std::getline(std::cin, s);
            std::cout<<"Введите кол-во разбиений: ";
            std::cin>>k;
            if(std::cin.fail()){
                error();
                continue;
            }else{
                std::cout<<'\n';
                st = true;
            }
        }
    }
    int getLucky() {
        if(s.empty()) return 0;
        std::string res{};
        int num;
        for(char c : s){
            char upper = toupper(c);
            num = upper - 'A' + 1;
            res += std::to_string(num);
        }
        num = 0;
        for(char c : res){
            num+= c - '0';
        }
        if( k == 1){
            return num;
        }
        int curr = num;
        for (int i = 0; i < k-1; i++) {
            std::string str = std::to_string(curr);
            curr = 0;
            for (char c : str) {
                curr += c - '0';
            }
        }
        return curr;
    }
    void out(const int r){
        std::cout<<"Ответ: "<< r << '\n';
    }
};

void play(){
    char stop{};
    do{
        Solution WOW;
        WOW.inp();
        int r = WOW.getLucky();
        WOW.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore(1000,'\n');
    }while(stop == 'y' || stop == 'Y');
}

int main(){
    play();
    return 0;
}