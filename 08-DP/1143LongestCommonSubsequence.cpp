#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
std::string text1{};
std::string text2{};
public:
    void inp(){
        std::cout<<"Введите первую строку: ";
        std::getline(std::cin, text1);
        std::cout<<"\nВведите вторую строку: ";
        std::getline(std::cin, text2);
        std::cout<<'\n';
    }
    int longestCommonSubsequence() {
        if(text1.empty() || text2.empty()) return 0;
        std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
        for(size_t i = 1; i < dp.size(); i++){
            for(size_t j = 1; j < dp[i].size(); j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
    void out(int r){
        std::cout<<"Длина наибольшей общей подпоследовательности: "<<r<<'\n';
    }
};

int main(){
    char stop{};
    std::cout<<"Наибольшая общая подпоследовательность\n";
    do{
        Solution s;
        s.inp();
        int r = s.longestCommonSubsequence();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
    }while(stop == 'y' || stop == 'Y');
}