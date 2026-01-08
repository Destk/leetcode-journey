#include<iostream>
#include<vector>
#include<limits>

std::vector<int> inp(){
    std::vector<int> v{};
    bool c = false;
    while(!c){
        std::cout<<"Введите кол-во лестниц: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            continue;
        }else{
            v.resize(x);
            for(int i = 0; i < x; i++){
                std::cout<<"\nВведите стоимость лестницы"<<i<<": ";
                std::cin>>v[i];
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
                    i--;
                    continue;
                }
            }
            c = true;
        }
    }
    return v;
}

int minCostClimbingStairs(std::vector<int>& cost) {
    std::vector<int> dp(cost.size()+1);
    dp[0] = 0;
    dp[1] = 0;
    for(size_t i = 2; i <= cost.size(); i++){
        dp[i] = std::min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
    }
    return dp.back();      
}
void out(int r){
    std::cout<<"Максимальаня сумма подъема составляет: "<<r<<'\n';
}
int main(){
    char c{};
    std::cout<<"Программа: ,,Подъем на вершину,,\n";
    do{
        std::vector<int> cost = inp();
        int r = minCostClimbingStairs(cost);
        out(r);
        std::cout<<"Продолжить?(y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}  