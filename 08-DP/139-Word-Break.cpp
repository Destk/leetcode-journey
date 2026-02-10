#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <unordered_set>

class Solution {
    private:
        std::string s; 
        std::vector<std::string> wordDict;
    public:
        void inp(){
            bool stop{false};
            while(!stop){
                std::cout<<"Введите кол-во слов в словаре: ";
                int x{};
                std::cin>>x;
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                    continue;
                }else{
		    std::cin.ignore();
                    for(int i = 0; i < x; i++){
                        std::cout<<"\nВведите слово: ";
                        std::string y{};
                        std::getline(std::cin, y);
                        wordDict.push_back(y);
                    }
                    std::cout<<"\nВведите строку s: ";
                    std::getline(std::cin,s);
                    stop = true;
                }
            }
        }

        bool wordBreak() {
            if(s.empty()) return false;
            std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
            std::vector<bool> cut(s.length() + 1, false);
            cut[0] = true;
            for(int i = 1; i <= s.size(); i++){
                for(int j = 0; j < i; j++){
                    if(cut[j] == true){
                        std::string sub = s.substr(j, i - j);
                        if(dict.find(sub) != dict.end()){
                            cut[i] = true;
                        }
                    }
                }
            }
            return cut[s.length()]; 
        }
        void out(bool r){
            if( r == true ){
                std::cout<<"строку 's' можно разделить на последовательность из одного или нескольких слов из словаря, разделенных пробелами.\n";
            }else{
                std::cout<<"строку 's' нельзя разделить на последовательность из одного или нескольких слов из словаря, разделенных пробелами.\n";
            }
        }
};

int main(){
    char c{};
    std::cout<<"Программа для проверки s и словаря строк wordDict верните true в том случае, если s можно разделить на последовательность из одного или нескольких слов из словаря, разделенных пробелами.\n";
    do{
        Solution s;
        s.inp();
        bool r = s.wordBreak();
        s.out(r);
        std::cout<<"Продолжить?(y/n): ";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}
