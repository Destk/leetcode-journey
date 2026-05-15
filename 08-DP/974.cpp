class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        std::unordered_map<int,int> map;
        map[0] = 1;
        int curr{0};
        int res{0};
        for(int i = 0;i < nums.size(); i++){
            curr = (curr + nums[i]) % k;
            if(curr < 0) curr+=k;
            res+=map[curr];
            map[curr]++;
        }
        return res;
    }
};
