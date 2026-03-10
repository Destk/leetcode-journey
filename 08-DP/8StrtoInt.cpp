#include <iostream>
#include <string>
#include <climits>
class Solution {
private:
    std::string s{};
public:
    void inp(){
        std::cout<<"Введите число: ";
        std::getline(std::cin, s);
        std::cout<<'\n';
    }
    int myAtoi() {
        if(s.empty()) return 0;
        int i{0};
        int sign{1};
        int res{0};
        while(i < s.size() && s[i] == ' '){
            i++;
        }
         if(s[i] == '-'){
                sign = -1;
                i++;
        }else if(s[i] == '+'){
            i++;
        }
        if(i >= s.size() || !std::isdigit(s[i])) return 0;
        while(i < s.size() && std::isdigit(s[i])){
            int tmp = s[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && tmp > INT_MAX % 10)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
            }
            res = res * 10 + tmp;
            i++;
        }
        return res*sign;
    }
    void out(int r){
        std::cout<<"Конвертированное число: "<<r<<'\n';
    }
};

int main(){
    char stop{};
    std::cout<<"String to int\n";
    do{
        Solution s;
        s.inp();
        int r = s.myAtoi();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
    }while(stop == 'y' || stop == 'Y');
}