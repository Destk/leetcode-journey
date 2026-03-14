#include <iostream>
#include <string>

class Solution {
private:
std::string haystack{};
std::string needle{};
public:
    void inp(){
        std::cout<<"Введите основную строку: ";
        std::getline(std::cin, haystack);
        std::cout<<"\nВведите подстроку строку: ";
        std::getline(std::cin, needle);
        std::cout<<'\n';
    }
    int strStr() {
        if(haystack.empty()) return -1;
        if(needle.empty()) return 0;
        int ptrs2{};
        int i = 0;
        while(i < haystack.length()){
            if(ptrs2 == needle.size()) break;
            if(haystack[i] == needle[ptrs2]){
                ptrs2++;
                i++;
            }else{
                if(ptrs2 > 0){
                    i = (i - ptrs2) + 1;
                    ptrs2 = 0;
                }else{
                    i++;
                }
            }
        }
        return (ptrs2 < needle.length() ? -1 : i - ptrs2);
    }
    void out(int r){
        std::cout<<"Ответ: " << r << '\n';
    }
};

int main(){
    char s{};
    std::cout<<"Задача на Поиск первого вхождения в подстроки!\n";
    do{
        Solution st;
        st.inp();
        int r = st.strStr();
        st.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>s;
        std::cin.ignore();
        std::cout<<"\n";
    }while(s == 'y' || s == 'Y');
}