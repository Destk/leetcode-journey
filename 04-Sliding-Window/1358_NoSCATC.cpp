//1358. Number of Substrings Containing All Three Characters
#include<iostream>
#include<string>
#include<limits>
#include<unordered_map>
//ввод
void InputS(std::string& s){
    std::cout<<"------- Программа по подсчету кол-ва подстрок с тремя символами ------\n";
    do{
        std::cout<<"Введи строку ,,s,, тольк из ,, a - b - c,,: \n";
        std::getline(std::cin,s);
        if(std::cin.fail() || s.find('a') != s.npos || s.find('b') != s.npos || s.find('c') != s.npos){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"ОШИБКА ВВОДА, ПОПРОБУЙТЕ ЕЩЁ РАЗ\n";
        }
    }while(std::cin.fail());
}
//решение задачи
int numberOfSubstrings(std::string s) {
    int l = 0, maxSum = 0;
    std::unordered_map<char, int> abc;
    
    for(int r = 0; r < s.size(); r++) {
        abc[s[r]]++;
        
        while(abc.count('a') && abc.count('b') && abc.count('c')) {
            maxSum += s.size() - r; 
            abc[s[l]]--;
            if(abc[s[l]] == 0) abc.erase(s[l]);  
            l++;
        }
    }
    return maxSum;
}
//вывод
void OutputR(int r){
    std::cout<<"количество подстрок содержащие ,,abc, - " << r <<'\n';
}

int main(){
    char c{};
    do{
        //подготовка для данных
        std::string s;
        //ввод
        InputS(s);
        //сохраняем результат в ,,r,,
        int r = numberOfSubstrings(s);
        //выводим
        OutputR(r);
        //продолжение
        std::cout<<"Продолжить? (y/n)\n";
        std::cin>> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}