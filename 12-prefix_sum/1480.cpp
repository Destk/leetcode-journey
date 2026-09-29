class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        if(nums.empty()) return {};
        std::vector<int> pref(nums.size());
        pref[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            pref[i] = pref[i-1] + nums[i];
        }
        return pref;
    }
};