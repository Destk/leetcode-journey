class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> map{};
        map[0] = 1;
        int curr{0};
        int total_num{0};
        for(int el : nums){
            curr += el;
            total_num+=map[curr-k];
            map[curr]++;
        }
        return total_num;    
    }
};
