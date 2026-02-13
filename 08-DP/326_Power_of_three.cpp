#include <iostream>
#include <limits>

class Solution {
private:
    int n;
public:
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"Введите число, котрое хотите проверить: ";
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
    bool isPowerOfThree() {
       if(n <= 0) return false;
       if(n == 1) return true; 
        while(n % 3 == 0){
            n = n / 3;
        }
        return n == 1;
    }
    void out(bool r){
        if(r == true){
            std::cout<<"Число является степенью 3-ки\n";
        }else{
            std::cout<<"Число не является степенью 3-ки\n";
        }
    }
};

int main(){
    std::cout<<"Программа по проверки числа на степень тройки\n";
    char stop{};
    do{
        Solution t;
        t.inp();
        bool r = t.isPowerOfThree();
        t.out(r);
        std::cout<<"Продолжить (y/n)? : ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
}