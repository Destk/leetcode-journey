#include <iostream>
#include <vector>

class Solution {
private:
    int n{};
    void error(){
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
    }
public:
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"Введите кол-во ступеней: ";
            std::cin>>n;
            if(std::cin.fail()){
                error();
                continue;
            }else{
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    int climbStairs() {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        std::vector<int> dp(n + 1,0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    void out(const int r) const{
        std::cout<<"Способы, чтобы подняться по лестнице :"<<r<<'\n';
    }
};
void play(){
    char stop{};
    std::cout<<"Программа на подсчет способов забраться по лестнице!\n";
    do{
        Solution s;
        s.inp();
        int r = s.climbStairs();
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
