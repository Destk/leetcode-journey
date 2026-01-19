#ifndef REC_H
#define REC_H
#include <string>

class Recommender{
    public:
    static std::string get_Score(int score);
    static std::string get_Rec(const std::string& pass);
};

#endif // REC_H