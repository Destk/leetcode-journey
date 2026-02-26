class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        if(nums.empty() || k == 0) return false;
        std::unordered_map<int,int> last;
        for(int i = 0; i < nums.size(); i++){
            if(last.count(nums[i])){
                int prev = last[nums[i]];
                if(i - prev <= k){
                    return true;
                }
            }
            last[nums[i]] = i;
        }
        return false;
    }
};
