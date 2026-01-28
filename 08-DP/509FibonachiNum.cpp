#include <iostream>
#include <limits>

class Solution {
private:
    int n{};
public:
    void SetN(){
        bool s{false};
        while(!s){
            std::cout<<"Введите число: ";
            std::cin>>n;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\nОшибка ввода, попробуйте еще раз!\n";
                continue;
            }
            s = true;
        }
    }
    int fib() {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int p1{0};
        int p2{1};
        for(int i = 2; i <= n; i++){
            int fib = p1+p2;
            p1 = p2;
            p2 = fib;
        }
        return p2;        
    }
    void out(int r){
        std::cout<<"\nПолучившиеся число Фибоначи: "<<r<<'\n';
    }
};

int main(){
    char stop{};
    std::cout<<"Программа: ,,Число фибоначи,,\n";
    do{
        Solution t;
        t.SetN();
        int r = t.fib();
        t.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<'\n';
    }while(stop == 'Y' || stop == 'y');
    return 0;
}