#include<iostream>
#include<vector>
#include<limits>
#include<climits>
#include<algorithm>


class Solution {
private:
    std::vector<int> coins;
    int amount{};
public:
    void inp(){
    bool s = false;
    while(!s){
        coins.clear();
        std::cout<<"Введите сумму для подсчета: ";
        std::cin>>amount;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            continue;
        }
        std::cout<<"\nВведите кол-во доступных купюр: ";
        int x{};
        std::cin>> x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            continue;
        }else{
            for(int i = 0; i < x; i++){
                std::cout<<"\nВведите наминал купюры: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                    i--;
                    continue;
                }
                coins.push_back(y);
            }
            s = true;
        }
    }
}
    int coinChange() {
        if(coins.empty()) return 0;
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i < amount + 1; i++){
            for(auto coin : coins){
                if(coin <= i && dp[i - coin] != amount + 1){
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }        
            }
        }
        int res = (dp[amount] == amount + 1) ?  -1 : dp[amount];
        return res;
    }
    void out(int r){
        if(r != -1){
            std::cout<<"Минимальное кол-во купюр: "<< r<<'\n';
        }else{
            std::cout<<"Нет необходимых купюр\n";
        }
    }
};

int main(){
    char c{};
    do{
        Solution s{};
        s.inp();
        int r = s.coinChange();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}