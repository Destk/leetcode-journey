class Solution {
public:
    int balancedStringSplit(string s) {
        int bal{0};
        int c{0};
        for(int i = 0; i < s.size();i++){
            if(s[i] == 'L') bal--;
            if(s[i] == 'R') bal++;
            if(bal == 0) c++;
        }
        return c;
    }
};
