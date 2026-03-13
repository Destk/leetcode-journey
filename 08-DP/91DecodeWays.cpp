#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
std::string s{};
public:
    void inp(){
        std::cout<<"Введите шифр: ";
        std::getline(std::cin, s);
        std::cout<<'\n';
    }
    int numDecodings() {
        if(s.empty()) return 0;
        std::vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for(size_t i = 1; i <= s.size(); i++){
            if(s[i-1] != '0'){
                dp[i]+=dp[i-1];
            }
            if(i >= 2){
                int two = (s[i-2] - '0') * 10 + (s[i-1] - '0');
                if(two >= 10 && two <= 26){
                    dp[i]+= dp[i-2];
                }
            }
        }
        return dp[s.size()];
    }
    void out(int r){
        std::cout<<"Кол-во вариантов расшифровки: " << r <<'\n';
    }
};

int main(){
    char stop{};
    do{
        Solution s;
        s.inp();
        int r = s.numDecodings();
        s.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
    return 0;
}