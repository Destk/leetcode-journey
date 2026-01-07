#include<iostream>
#include<vector>
#include<limits>

std::vector<int> inp(){
    std::vector<int> v{};
    bool s = false;
    while(!s){
        std::cout<<"Введите кол-во элементов в массиве: ";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
            continue;
        }else{
            for(int i = 0; i < x; i++){
                std::cout<<"Вводите элементы массвиа: ";
                int y{};
                std::cin>>y;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                    i--;
                    continue; 
                }
                v.push_back(y);
            }
            s = true;
        }
    }
    return v;
}

bool canJump(std::vector<int>& nums) {
    if(nums.empty()) return false;
    if(nums.size() == 1) return true;
    std::vector<bool> dp(nums.size(),false);
    dp[0] = true;
    for(size_t i = 0; i < nums.size(); i++){
        if(dp[i] == true){
            for(size_t j = i+1; j <= std::min(i+nums[i], nums.size()-1); j++){
                dp[j] = true;
            }
        }
    }
    return dp.back();         
}

void out(bool r){
    if(r == true){
        std::cout<<"Пользователь смог допрыгнуть\n";
    }else{
        std::cout<<"Пользователь не смог допрыгнуть\n";
    }
}
int main(){
    char c{};
    std::cout<<"Программа по Прыжкам\n";
    do{
        std::vector<int> nums = inp();
        bool r = canJump(nums);
        out(r);
        std::cout<<"Продолжить?(y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}