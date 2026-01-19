#include <iostream>
#include <limits>
#include "../include/scorer.h"
#include "../include/recommender.h"

void inp(std::string& p){
    std::cout<<"Введите пароль: ";
    std::getline(std::cin, p);
    std::cout<<'\n';
}
int main(){
    char s{};
    std::cout<<"Программа по оценке пароля\n";
    do{
        std::string password;
        inp(password);
        int score = Scorer::status(password);           
        std::string level = Recommender::get_Score(score);  
        std::string tips = Recommender::get_Rec(password);      
        std::cout << "Score: " << score << "/100\n" << level << tips;
        std::cout<<"Продолжить? (y/n): ";
        std::cin>> s;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(s == 'y' || s == 'Y');
    return 0;
}