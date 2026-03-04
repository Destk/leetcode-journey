#include <iostream>
#include <vector>
#include <string>
#include <stack>
class Solution {
private:
std::vector<std::string> tokens{};
public:
    void inp(){
        std::cout<<"Введите ваше выражение: ";
        std::string s{};
        std::getline(std::cin, s);
        tokens.clear();  
        std::string token;
        for (char c : s) {
            if (c == ' ') {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
            } else {
                token += c;
            }
        }
        if (!token.empty()) {
            tokens.push_back(token);
        }
        std::cout<<'\n';
    }
    int evalRPN() {
        if(tokens.empty()) return 0;
        std::stack<int> op;
        for(size_t i = 0; i  < tokens.size(); i++){
            if(tokens[i] == "+"){
                int b = op.top();
                op.pop();
                int a = op.top();
                op.pop();
                op.push(a + b);
            }else if(tokens[i] == "-" ){
                int b = op.top();
                op.pop();
                int a = op.top();
                op.pop();
                op.push(a - b);
            }else if(tokens[i] == "/"){
                int b = op.top();
                op.pop();
                int a = op.top();
                op.pop();
                op.push(a / b);
            }else if(tokens[i] == "*"){
                int b = op.top();
                op.pop();
                int a = op.top();
                op.pop();
                op.push(a * b);
            }else{
                int num = std::stoi(tokens[i]);
                op.push(num);
            }
        }
        return op.top();
    }
    void out(const int r){
        std::cout<<"Результат вашего выражения: "<<r<<'\n';
    }
};

int main(){
    std::cout<<"Программа на: << Подсчёт обратной польской записи>>\n";
    char stop{};
    do{
        Solution p;
        p.inp();
        int r = p.evalRPN();
        p.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
    return 0;
}