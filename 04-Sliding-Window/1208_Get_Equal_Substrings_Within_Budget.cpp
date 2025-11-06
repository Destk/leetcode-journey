// 1208. Get Equal Substrings Within Budget
#include<iostream>
#include<string>
#include<limits>
//ввод
void InputSTC(std::string& s, std::string& t, int& maxCost ){
    std::cout<<"------ ,,Программ: поиск равной подстроки в рамках бюджета,, ------\n";
    do{
        std::cout<<"Введи строку фиксированной длины для ,,s,,: \n";
        std::getline(std::cin,s);
        std::cout<<"Введи строку ,,t,, равной длине строки ,,s,,: \n";
        std::getline(std::cin,t);
        std::cout<<"Введи бюджет ,,maxCost,,: \n";
        std::cin >> maxCost;
        if(std::cin.fail() || s.length() != t.length() || s.empty() || t.empty()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"ОШИБКА ВВОДА, попробуйте ещё раз\n";
        }
    }while(std::cin.fail());
}
//решение задачи
int equalSubstring(std::string s, std::string t, int maxCost) {
    //  левая грань, макс длина, сумма аски  
    int l{}, maxLen{0},asciiSum{};
    //от о до конца(т к по услоыию строки одинаковой длины)
    for(size_t r = 0; r < s.size(); r++){
        //считаем сумму аски
        asciiSum += std::abs(s[r] - t[r]);
        //пока сумма аски больше кост, то вычитаем аски и делаем шаг
        while(asciiSum > maxCost){
            asciiSum -= std::abs(s[l] - t[l]);
            l++;  
        }
        //формула подсчета длины
        int currLen = r - l + 1;
        //ищем максимум
        maxLen = std::max(maxLen,currLen);
    }
    //вернули максимум 
    return maxLen;   
    }
//вывод
void OutputR(int r){
    if(r != 0){
        std::cout<<"Максимальная длина подстроки ,,s,, , которую изменили под строку ,,t,, - " << r << '\n';
    }else{
        std::cout<<"Нет нужной подстроки\n";
    }
}
int main(){
    char c{};
    do{
        //данные нужные для задачи
        std::string s;
        std::string t;
        int maxCost{};
        //ввод
        InputSTC(s,t,maxCost);
        //сохраняем результат в r
        int r = equalSubstring(s,t,maxCost);
        //вывод
        OutputR(r);
        //продолжение
        std::cout<<"Продолжить? (y/n)\n";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c=='y' || c == 'Y');
    return 0;
}