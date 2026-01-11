#include<iostream>
#include<vector>
#include<limits>
#include<climits>
#include<algorithm>

void inp(std::vector<int>& coins, int& amount){
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

int coinChange(std::vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    if(coins.empty()) return -1;

    std::vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;

    for(size_t i = 1; i < dp.size(); i++){
        for(size_t j = 0; j < coins.size(); j++){
            if(coins[j] <= i && dp[i-coins[j]] != INT_MAX){
                dp[i] = std::min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    return (dp[amount] != INT_MAX) ? dp[amount] : -1;            
}

void out(int r){
    if(r != -1){
        std::cout<<"Минимальное кол-во купюр: "<< r<<'\n';
    }else{
        std::cout<<"Нет необходимых купюр\n";
    }
}

int main(){
    char c{};
    do{
        int amount{};
        std::vector<int> coins{};
        inp(coins,amount);
        int r = coinChange(coins,amount);
        out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}