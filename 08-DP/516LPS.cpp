#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
std::string s{};
public:
    void inp(){
        std::cout<<"Введите строку: ";
        std::getline(std::cin, s);
        std::cout<<'\n';
    }
    int longestPalindromeSubseq() {
        if(s.empty()) return 0;
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
        for(size_t i = 0; i < dp.size(); i++){
            dp[i][i] = 1;
        }
        for(int len = 2; len <= s.size(); len++){
            for(int i = 0; i <= s.size() - len; i++){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    if(len == 2){
                        dp[i][j] = 2;
                    }else{
                        dp[i][j] = 2 + dp[i+1][j-1];
                    }
                }else{
                    dp[i][j] = std::max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
    void out(int r){
        std::cout<<"Маскимальная длина палиндрома: "<<r<<'\n';
    }
};

int main(){
    char stop{};
    do{
        Solution s;
        s.inp();
        int r = s.longestPalindromeSubseq();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cin.ignore();
    }while(stop == 'y' || stop == 'Y');
}