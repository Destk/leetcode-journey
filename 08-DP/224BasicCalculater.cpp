#include <iostream>
#include <string>
#include <stack>

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
        std::stack<int> st;
        int res{};
        int curr{};
        int sign{1};
        for(size_t i = 0; i < s.size(); i++){
            if(std::isdigit(s[i])){
                curr = curr * 10 + (s[i] - '0');
            }
            else if(s[i] == '-'){
                res += curr * sign;
                curr = 0;
                sign = -1;
            }else if(s[i] == '+'){
                res += curr * sign;
                curr = 0;
                sign = 1;
            }else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                res = 0;
            }else if(s[i] == ')'){
                res += sign * curr; 
                curr = 0;
                int prev_sign = st.top(); st.pop();
                int prev_res  = st.top(); st.pop();
                res = prev_res + prev_sign * res;
            }
        }
        res += sign * curr;
        return res;
    }
    void out(int r){
        std::cout<<"Ответ: " <<r<<'\n';
    }
};

int main(){
    char stop{};
    std::cout<<"Простой калькулятор с двумя мат функциями + и -\n";
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