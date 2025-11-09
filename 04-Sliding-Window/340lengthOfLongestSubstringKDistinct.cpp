//340lengthOfLongestSubstringKDistinct.cpp
#include<iostream>
#include<string>
#include<limits>
#include<string>
#include<unordered_map>
//ввод
void InputSK(std::string& s, int& k){
    std::cout<<"Программа: Поиск максимально длинной строки в которой не более ,,к,, уникальных элементов\n";
    do{
        std::cout<<"Введите ,,k,,: \n";
        std::cin>>k;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Введите строку ,,s,,: \n";
        std::getline(std::cin,s);
        if(std::cin.fail() || s.empty()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"ОШИБКА ВВОДА, ПОПРОБУЙТЕ ЕЩЕ РАЗ\n";
        }
    }while(std::cin.fail());
}
//решение задачи
int lengthOfLongestSubstringKDistinct(std::string s, int k){
    //инициализируем нужные переменнуы (левая грань, макс длина, счетчик для кол-во уникальных элементов)
    int l{},maxLen{},countUn{};
    //хэш-мапа для текущего окна и подсчету букв
    std::unordered_map<char,int> wind;
    //основной цикл 
    for(size_t r = 0; r < s.size(); r++){
        //добавляем в мапу буквы
        wind[s[r]]++;
        //создаем переменную для подсчета текущего окна
        int currWind{};
        //если буква встречалась +1 к счетчику
        if(wind[s[r]] == 1){
            countUn++;
        }
        //пока счетчик больше доступных к
        while(countUn > k){
            //двигаем окно
            wind[s[l]]--;
            //если эл встречался, -1
            if(wind[s[l]] == 0){
                countUn--;
            }
            l++;
        }
        //базовая формула для подсчета длины
        currWind = r - l + 1;
        //обновляем максимум
        maxLen = std::max(maxLen, currWind);
    }
    //возвращаем макс длину
    return maxLen;
}
//вывод
void OutputR(int r){
    std::cout<<"Максимально длинная строка в которой не более ,,к,, уникальных элементов: " << r<<'\n';
} 
int main(){
    char c;
    do{
        std::string s;
        int k{};
        //ввод
        InputSK(s,k);
        //решение
        int r = lengthOfLongestSubstringKDistinct(s,k);
        //вывод
        OutputR(r);
        //продолжить
        std::cout<<"Продолжить? (y/n)\n";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}
