#include <iostream>
#include <string>
#include <limits>

class Solution {
        std::string s;
    public: 
        void setS(){
            std::cout<<"Введите палиндром: ";
            std::getline(std::cin, s);
            std::cout<<'\n';
        }
        std::string longestPalindrome() {
            if(s.empty()) return "Пустая строка!";
            int maxlen{1};
            int st{0};
            for(int i = 0; i < s.size(); i++){
                int l = i;
                int r = i;
                while(l >= 0 && r < s.size() && s[l] == s[r]){
                    l--;
                    r++;
                }
                int len = r - l - 1;
                if(maxlen < len){
                    maxlen = len;
                    st = l + 1;
                }
                l = i;
                r = i+1;
                while(l >= 0 && r < s.size() && s[l] == s[r]){
                    l--;
                    r++;
                }
                len = r - l - 1;
                if(maxlen < len){
                    maxlen = len;
                    st = l + 1;
                }
            } 
            return s.substr(st,maxlen);      
        }

        void GetS(const std::string& r){
            std::cout<<"Самый длинный палиндром в подстроке: "<<r<<'\n';
        }
};

int main(){
    char c{};
    std::cout<<"Программа по поиску самого длинного палиндрома в строке\n";
    Solution p;
    do{
        p.setS();
        std::string r = p.longestPalindrome();
        p.GetS(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>c;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}