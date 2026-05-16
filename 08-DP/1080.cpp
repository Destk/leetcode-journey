class Solution {
public:
    int numPairsDivisibleBy60(std::vector<int>& time) {
        if(time.empty()) return 0;
        std::unordered_map<int,int> map{};
        int curr{};
        int res{};
        for(int i = 0; i < time.size(); i++){
            curr = time[i] % 60;
            int need = (60 - curr) % 60;
            res += map[need];
            map[curr]++;
        }
        return res;
    }
};
