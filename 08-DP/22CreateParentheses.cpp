#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <functional>

class Solution {
private:
int n{};
public:
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"Введите кол-во пар скобок: ";
            std::cin>>n;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                continue;
            }else{
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    std::vector<std::string> generateParenthesis() {
        if( n < 0 || n > 8) return {};
        int open{n};
        int close{n};
        std::string s{};
        std::vector<std::string> res{};
        std::function<void()> rec;
        rec = [&](){
            if(s.length() == 2*n){
                res.push_back(s);
                return;
            }
            if(open > 0){
                open--;
                s+="(";
                rec();
                open++;
                s.pop_back();
            }if(close > open){
                close--;
                s+=")";
                rec();
                close++;
                s.pop_back();
            }
        };
        rec();
        return res;
    }
    void out(const std::vector<std::string>& res){
        std::cout<<"Получишиеся пары скобок: ";
        for(const auto& el : res){
            std::cout<<el <<" ";
        }
        std::cout<<'\n';
    }
};

int main(){
    char stop{};
    std::cout<<"Программа для создания пар скобок\n";
    do{
        Solution x;
        x.inp();
        std::vector<std::string> r = x.generateParenthesis();
        x.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<'\n';
    }while(!stop);
}