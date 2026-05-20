class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char,int> map{};
        int left{0};
        int count{0};
        for(int i = 0; i < s.size(); i++){
            if(map.count(s[i]) && map[s[i]] >= left){
                left = map[s[i]]+1;
            }
            map[s[i]] = i;
            int len = i - left + 1;
            count = std::max(len,count);
        }
        return count;
    }
};
