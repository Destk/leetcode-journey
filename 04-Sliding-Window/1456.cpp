class Solution {
public:
    int maxVowels(std::string s, int k) {
        std::unordered_set<char> set = {'a','e','i','o','u'};
        int c{0};
        for(int i = 0; i < k; i++){
            if(set.count(s[i])){
                c++;
            }
        }
        int maxC{c};
        for(int i = k; i < s.size(); i++){
            if (set.count(s[i - k])) c--;
            if(set.count(s[i])){
                c++;
            }
            maxC = std::max(c,maxC);
        }
        return maxC;
    }
};
