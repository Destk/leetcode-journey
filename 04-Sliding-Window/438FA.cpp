//438FA.cpp
#include<iostream>
#include<string>
#include<limits>
#include<string>
#include<vector>
#include<unordered_map>
//ввод
void InputSK(std::string& s, std::string& p){
    std::cout<<"Программа: Поиск всех аннаграмм и вывод их первых индексов\n";
    do{
        std::cout<<"Введите строку ,,s,,: \n";
        std::getline(std::cin,s);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Введите строку ,,p,,: \n";
        std::getline(std::cin,p);
        if(std::cin.fail() || s.empty() || p.empty()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"ОШИБКА ВВОДА, ПОПРОБУЙТЕ ЕЩЕ РАЗ\n";
        }
    }while(std::cin.fail());
}
//решение задачи
std::vector<int> findAnagrams(std::string s, std::string p) {
    if (p.length() > s.length()) return {};
    
    std::unordered_map<char, int> need, window;
    for (char c : p) need[c]++;
    
    std::vector<int> result;
    int left = 0, count = 0;
    
    // Инициализация первого окна
    for (int right = 0; right < p.length(); right++) {
        char c = s[right];
        window[c]++;
        if (need.count(c) && window[c] == need[c]) {
            count++;
        }
    }
    
    if (count == need.size()) {
        result.push_back(0);
    }
    
    // Движение окна
    for (int right = p.length(); right < s.length(); right++) {
        // Добавляем правый символ
        char right_char = s[right];
        window[right_char]++;
        if (need.count(right_char) && window[right_char] == need[right_char]) {
            count++;
        }
        
        // Убираем левый символ
        char left_char = s[left];
        if (need.count(left_char) && window[left_char] == need[left_char]) {
            count--;
        }
        window[left_char]--;
        left++;
        
        // Проверяем условие
        if (count == need.size()) {
            result.push_back(left);
        }
    }
    
    return result;
}
//вывод
void OutputR(std::vector<int> r){
    std::cout<<"Все аннаграмм по начальным индексам : " <<'\n';
    for(int i : r){
        std::cout<< i;
    }
} 
int main(){
    char c;
    do{
        std::string s;
        std::string p;
        //ввод
        InputSK(s,p);
        //решение
        std::vector<int> r = findAnagrams(s,p);
        //вывод
        OutputR(r);
        //продолжить
        std::cout<<"Продолжить? (y/n)\n";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}
