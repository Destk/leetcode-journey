class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if(needle.empty()) return 0;    
        if(needle.size() > haystack.size()) return -1;
        std::vector<int> lps;
        lps.resize(needle.size());
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < needle.size()) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        i = 0; 
        int j = 0;
        while (i < haystack.size()) {
            if (j == needle.size()) {
                return i - j; // нашли
            }
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps[j - 1]; // откат
                } else {
                    i++;
                }
            }
        }
        if (j == needle.size()) return i - j;
        return -1;
    }
};
