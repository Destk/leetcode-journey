#include <iostream>
#include <stack>
#include <string>

class Solution {
private:
    std::string s{};
public:
    void inp(){
        std::cout<<"Введите просто мат (только +/-) выражение: ";
        std::getline(std::cin, s);
        std::cout<<'\n';
    }
    int calculate() {
        if(s.empty()) return 0;
        int res{};
        int curr{};
        int prev{};
        char sign{'+'};
        for(size_t i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(std::isdigit(s[i])){
                curr = curr * 10 + (s[i] - '0');
            }
            if(!std::isdigit(s[i]) || i == s.size()-1){
                if(sign == '+'){
                    res += curr;
                    prev = curr;
                }
                else if(sign == '-'){
                    res -= curr;
                    prev = -curr;
                }
                else if(sign == '*'){
                    res = res - prev + (prev * curr);
                    prev = prev * curr;
                }
                else if(sign == '/'){
                    res = res - prev + (prev / curr);
                    prev = prev / curr;
                }
                sign = s[i];
                curr = 0;
            }
        }
        return res;
    }
    void out(int r){
        std::cout<<"Ответ: " <<r<<'\n';
    }
};

int main(){
    char stop{};
    std::cout<<"Простой калькулятор\n";
    do{
        Solution s;
        s.inp();
        int r = s.calculate();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout << '\n';
    }while(stop == 'y' || stop == 'Y');
    return 0;
}