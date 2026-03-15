class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res{};
        for(int i = 0; i <= nums.size(); i++){
            res^=i;
        }
        for(auto num : nums){
            res^=num;
        }
        return res;
    }
};
