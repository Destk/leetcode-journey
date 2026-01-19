#include "../include/scorer.h"
#include <iostream>
#include <cctype>
int Scorer::status(const std::string& pass){
    //оценка длины
    int len_score = pass.length()*3;
    // наличие заглавных
    int capital_score{};
    for(const auto& w : pass){
        if(std::isupper(static_cast<unsigned char> (w))){
            capital_score=20;
            break;
        }
    }
    //наличие спец-символов
    int spec_score{};
    const std::string specials = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    for(const auto& c : pass) {
    if (specials.find(c) != std::string::npos) {
        spec_score = 25; 
        break;
    }
}

    //наличие цифр
    int num_score{0};
    bool check{false};
    for(const auto& n : pass){
        if(std::isdigit(static_cast<unsigned char> (n))){
            check = true;
            break;
        }
    }
    if(check){
        num_score=15;
    }
    int score =len_score+capital_score+spec_score+num_score;
    bool has_diversity = (capital_score > 0) && (num_score > 0) && (spec_score > 0);
    if (has_diversity) score += 10;

    return std::min(score, 100);
}