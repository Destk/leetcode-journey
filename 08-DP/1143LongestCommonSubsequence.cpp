#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
std::string s1{};
std::string s2{};
public:
    void inp(){
        std::cout<<"Введите первую строку: ";
        std::getline(std::cin, s1);
        std::cout<<"\nВведите вторую строку: ";
        std::getline(std::cin, s2);
        std::cout<<'\n';
    }
    int longestCommonSubsequence() {
        if(s1.empty() || s2.empty()) return 0;
        std::vector<std::vector<int>> dp(s1.size()+1, std::vector<int>(s2.size()+1, 0));
        for(int i = 1; i <= s1.size(); i++){
            for(int j = 1; j <= s2.size(); j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
    void out(int r){
        std::cout<<"Длина наибольшей общей подпоследовательности: "<<r<<'\n';
    }
};

void play(){
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
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
}

int main(){
    play();    
    return 0;
}