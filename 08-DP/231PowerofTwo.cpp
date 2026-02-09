#include <iostream>
#include <limits>

class Solution {
    private:
        int n;
    public:
        Solution() : n(0) {};
        void inpN(){
            bool stop{false};
            while(!stop){
                std::cout<<"Введите число для проверки на степень двойки: ";
                std::cin>>n;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout<<"\nОшибка ввода, поробуйте ещё раз!\n";
                }else{
                    std::cout<<'\n';
                    stop = true;
                }
            }
        }
        bool isPowerOfTwo() {
            if(n <= 0 ) return false;
            if( n == 1) return true;
            while( n > 1){
                if(n % 2 != 0) return false;
                n = n / 2;
            }
            return true;
        }
        void outR(bool r){
            if(r == true){
                std::cout<<"Число является степенью двойки\n";
            }else{
                std::cout<<"Число не является степенью двойки\n";
            }
        }
};


int main(){
    char c{};
    std::cout<<"Программа для проверки степеней 2-ки\n";
    do{
        Solution pow;
        pow.inpN();
        bool r = pow.isPowerOfTwo();
        pow.outR(r);
        std::cout<<"Продолжить?(y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}
