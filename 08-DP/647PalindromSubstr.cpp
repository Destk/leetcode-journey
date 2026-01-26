#include <iostream>
#include <string>
#include <limits>

class Solution {
private:
    std::string s;
public:
    void setS(){
        std::cout<<"Введите палиндром: ";
        std::getline(std::cin, s);
        std::cout<<'\n';
    }
    int countSubstrings() {
        if(s.empty()) return 0;
        int countS{0};
        for(int i = 0; i < s.size(); i++){
            int l = i;
            int r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                countS++;
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                countS++;
                l--;
                r++;
            }
        }
        return countS;        
    }
    void GetS(const int r){
           std::cout<<"Кол-во палиндромов в подстроке: "<<r<<'\n';
    }
};

int main(){
    char c{};
    std::cout<<"Программа по подсчёту палиндромов в подстроке\n";
    Solution p;
    do{
        p.setS();
        int r = p.countSubstrings();
        p.GetS(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}   