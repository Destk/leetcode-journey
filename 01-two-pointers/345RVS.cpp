class Solution {
public:
    std::string reverseVowels(std::string s) {
       if(s.empty()) return "";
       unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
       int l = 0;
       int r = s.size()-1;
       while(l < r){
        if(vowels.count(s[l]) && vowels.count(s[r])){
            std::swap(s[l],s[r]);
            l++;
            r--;
        }else if(vowels.count(s[l]) == 0){
            l++;
        }else{
            r--;
        }
       }
       return s; 
    }
};
