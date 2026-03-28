#include <iostream>
#include <limits>
#include <unordered_map>
class Solution {
public:
    bool isHappy(int n) {
        if(n == 1 || n == 7) return true;
        std::unordered_map<int, bool> check{};
        while(n != 1 && check[n] == false){
            check[n] = true;
            int sum{0};
            int n_n = n;
            while (n_n != 0){
                int tmp = n_n % 10;
                sum = sum + (tmp * tmp);
                n_n = n_n / 10;
            }
            if(sum == 1){
                return true;
            }
            n = sum;
        }
        return false;
    }
};

void inp(int& n){
    bool stop{false};
    while(!stop){
        std::cout<<"Введите число: ";
        std::cin>>n;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте еще раз!\n";
            continue;
        }else{
            stop = true;
        }
    }
}
bool out(bool r){
    std::cout<<"Число " << r <<" счастливое\n";
}
int main(){
    int n{};
    inp(n);
    Solution s;
    bool r = s.isHappy(n);
    out(r);
    std::cout<< n % 10 << '\n' << n / 10;
}