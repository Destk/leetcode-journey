#include <iostream>
#include <vector>

class Solution {
private:
    int n{};
public:
    void inp(){
        bool s{false};
        while(!s){
            std::cout<<"Введите число: ";
            std::cin>>n;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибкаа ввода, попробуйте ещё раз!\n";
            }else{
                s = true;
                std::cout<<'\n';
            }
        }
    }
    int tribonacci() {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        std::vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
     void out(int r){
        std::cout<<"Число Трибоначи " << r << '\n';
    }
};

void play(){
    char stop{};
    std::cout<<"Задача на поиск наибольшей возрастающей подпоследовательности\n";
    do{
        Solution s;
        s.inp();
        int r = s.tribonacci();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
}
int main(){
    play();
    return 0;
}