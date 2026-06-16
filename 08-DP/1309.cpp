class Solution {
public:
    string freqAlphabets(string s) {
        string r{};
        for(int i = s.size()-1; i >= 0; ){
            if(s[i] == '#'){
                int n = (s[i-2] - '0') * 10 + (s[i-1] - '0');
                char letter = 'a' + n - 1;
                r+=letter;
                i -= 3;
            }else{
                int n = (s[i] - '0');
                int letter = 'a' + n - 1;
                r+=letter;
                i--;
            }
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
