class Solution {
public:
    std::vector<string> letterCasePermutation(std::string s) {
        if(s.empty()) return {};
        std::vector<string> res{};
        std::string str{};
        std::function<void(int)> func;
        func = [&] (int ind){
            if(str.size() == s.size()){
                res.push_back(str);
                return;
            }
            if(std::isdigit(s[ind])){
                str.push_back(s[ind]); 
                func(ind+1);
                str.pop_back();
            }else{
                str.push_back(tolower(s[ind]));
                func(ind + 1);
                str.pop_back();

                str.push_back(toupper(s[ind]));
                func(ind + 1);
                str.pop_back();
            }
        };
        func(0);
        return res;
    }
};
