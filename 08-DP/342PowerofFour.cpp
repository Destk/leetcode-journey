#include <iostream>
#include <limits>

class Solution {
    private:
        int n;
    public:
        void inp(){
            bool stop{false};
            while(!stop){
                std::cout<<"Введите число: ";
                std::cin>>n;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                }else{
                    stop = true;
                    std::cout<<'\n';
                }
            }
        }
        bool isPowerOfFour() {
            if(n == 0) return false;
            if(n == 1) return true;
            while(n % 4 == 0){
                n = n / 4;
            }
            if(n == 1){
                return true;
            }
            return false;
        }
        void out(bool r){
            if(r){
                std::cout<<"Число является степенью 4\n";
            }else{
                std::cout<<"Число не является степенью 4\n";
            }
        }
};

int main(){
    char c{};
    std::cout<<"Программа для проверки степеней 4-ки\n";
    do{
        Solution pow;
        pow.inp();
        bool r = pow.isPowerOfFour();
        pow.out(r);
        std::cout<<"Продолжить?(y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}