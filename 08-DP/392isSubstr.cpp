class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (s.empty()) return true;
        if (t.empty()) return false;
        if (s.size() > t.size()) return false;
        size_t ind{0};
        for(size_t i = 0; i < s.size(); i++){
            bool f{false};
            for(size_t j = ind; j < t.size(); j++){
                if(s[i] == t[j]){
                    ind = j + 1;
                    f = true;
                    break;
                }
            }
            if(!f){
                return false;
                }
        }
        return true;
    }
};
