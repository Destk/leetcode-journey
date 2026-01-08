#include<iostream>
#include<vector>
#include<limits>

std::vector<int> inp(){
    std::vector<int> v{};
    bool c = false;
    while(!c){
        std::cout<<"Введите кол-во домов: ";
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
                std::cout<<"\nВведите кол-во сбережений в доме "<<i<<": ";
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

int rob(std::vector<int>& nums) {
    std::vector<int> dp(nums.size());
    dp[0] = nums[0];
    if(nums.size()>1){
        dp[1] = std::max(nums[1],dp[0]);
    }
    for(size_t i = 2; i < nums.size(); i++){
        dp[i] = std::max(dp[i-1], dp[i-2]+nums[i]);
    }
    return dp[nums.size()-1];
}

void out(int r){
    std::cout<<"Максимальаня сумма награбленного составляет: "<<r<<'\n';
}
int main(){
    char c{};
    std::cout<<"Программа: ,,Грабитель домов,,\n Правило - Запрещено грабить соседние дома, иначе приедет полиция\n";
    do{
        std::vector<int> nums = inp();
        int r = rob(nums);
        out(r);
        std::cout<<"Продолжить?(y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}