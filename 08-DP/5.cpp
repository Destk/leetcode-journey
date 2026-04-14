class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if(s.empty()) return "";
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), 0));
        int maxlen{1};
        int st{0};
         // Длина 1
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
        }
        
        // Длина 2
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                st = i;
                maxlen = 2;
            }
        }
        // Длина 3
        for(int sub = 3; sub <= s.size(); sub++){
            for(int i = 0; i + sub - 1 < s.size(); i++){
                int j = i + sub - 1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                    if(sub > maxlen){
                        st = i;
                        maxlen = sub;
                    }
                }
            }
        }
        return s.substr(st, maxlen);
    }
};