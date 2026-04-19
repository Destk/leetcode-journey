#include <iostream>
#include <vector>

class Solution {
private:
    std::vector<int> nums{};
public:
    int roblin(std::vector<int>& nums, int st, int end){
        std::vector<int> dp(end - st + 1, 0);
        if(dp.size() == 1) return nums[st];
        dp[0] = nums[st];
        dp[1] = std::max(nums[st], nums[st+1]);
        for(int i = 2; i < dp.size(); i++){
            dp[i] = std::max(dp[i-1], dp[i-2]+nums[st + i]);
        }
        return dp[dp.size()-1];
    }
    void error(){
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
    }
    void inp(){
            bool c = false;
            while(!c){
                std::cout<<"Введите кол-во домов: ";
                int x{};
                std::cin>>x;
                if(std::cin.fail()){
                    error();
                    continue;
                }else{
                    nums.resize(x);
                    for(int i = 0; i < x; i++){
                        std::cout<<"\nВведите кол-во сбережений в доме "<<i<<": ";
                        std::cin>>nums[i];
                        if(std::cin.fail()){
                            error();
                            i--;
                            continue;
                        }
                    }
                    c = true;
                }
            }
    }
    int rob() {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int n = nums.size();

        int var1 = roblin(nums, 0, n-2);
        int var2 = roblin(nums, 1, n-1);

        return std::max(var1,var2);
    }
    void out(const int r) const{
        std::cout<<"Максимальный куш: "<<r<<'\n';
    }
};
void play(){
    char stop{};
    std::cout<<"Задача House Robber\n";
    do{
        Solution s;
        s.inp();
        int r = s.rob();
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