//159_SML
#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<limits>
//ввод
void InputS(std::string& s){
    std::cout<<"---Программа по поиску самую длинную подстроку, содержащую не более двух различных символов---\n";
    do{
        std::cout<<"Введите строку ,,s,,: \n";
        std::getline(std::cin,s);
        if(std::cin.fail() || s.empty()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Ошибка Ввода, попробуйте ещё раз\n";
        }
    }while(std::cin.fail());
}
//функция для нахождения макс строки
int SearchMaxLenght(std::string s){
    //крайние условия
    if(s.size() == 1){
        return 1;
    }
    //иницализация основных данных
    int l{},maxlen{},countUn{};
    std::unordered_map<char, int> window;
    //основной цикл
    for(size_t r = 0; r < s.size(); r++){
        int currLen{};
        window[s[r]]++;
        if(window[s[r]] == 1){
            countUn++;
        }
        //сужение окна
        while(countUn >= 2){
            window[s[l]]--;
            if(window[s[l]] == 0){
                countUn--;
            }
            l++;
        }
        //обновление результата
        currLen = r - l + 1;
        maxlen = std::max(currLen,maxlen);
    }
    return maxlen;
}
//функция вывода
void OutputR(int r){
    std::cout<<"самая длинная подстрока, содержащая не более двух различных символов "<<r<<'\n';
}
//основная функция
int main(){
    char c{};
    do{
        //подготовка для данных
        std::string s;
        //ввод
        InputS(s);
        //решение
        int r = SearchMaxLenght(s);
        //вывод
        OutputR(r);
        //продолжение
        std::cout<<"Продолжить ? (y/n)\n";
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}