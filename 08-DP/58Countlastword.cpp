class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int last_ind = s.length()-1;
        while(last_ind >= 0 && s[last_ind] == ' '){
            last_ind--;
        }
        int count_word{0};
        while(last_ind >= 0 && s[last_ind] != ' '){
            count_word++;
            last_ind--;
        }
        return count_word;
    }
};
