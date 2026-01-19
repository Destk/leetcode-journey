#include "../include/recommender.h"

std::string Recommender::get_Score(int score){
    if(score <= 40 ){
        return "Плохо\n";
    }
    else if ( score > 40 && score <= 60){
        return "Хорошо\n";
    }else{
        return "Отлично\n";
    }
}

std::string Recommender::get_Rec(const std::string& pass){
    std::string rec = "Рекомендации для улучшения пароля: \n";
    //оценка длины
    if(pass.length() <= 12) rec+="Нужна Длина 12+\n";
    // наличие заглавных
    bool has_upper{false};
    for(const auto& w : pass){
        if(std::isupper(static_cast<unsigned char> (w))){
            has_upper = true;
        }
    }
    if(!has_upper){
        rec+="Добавьте заглаыные\n";
    }
    //наличие спец-символов
    bool has_spec = false;
    const std::string specials = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    for(const auto& c : pass) {
    if (specials.find(c) != std::string::npos) {
        has_spec = true;
        break;
    }
    }
    if(!has_spec){
        rec+="Добавьте спец символы(!@#$%^&*()_+-=[]{}|;:,.<>?)\n";
    }

    //наличие цифр
    bool has_num = false;
    for(const auto& n : pass){
        if(std::isdigit(static_cast<unsigned char> (n))){
            has_num = true;
            break;
        }
    }
    if(!(has_num)){
        rec+="Добавьте цифры\n";
    }
    return rec;
}