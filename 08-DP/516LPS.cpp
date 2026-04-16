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
        int n = s.length();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n,0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 2;
            } else {
                dp[i][i+1] = 1;
            }
        }
        for(int len = 3; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }else{
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
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