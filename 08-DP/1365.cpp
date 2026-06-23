class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        vector<int> res;
        for (int x : nums) {
            int count = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
            res.push_back(count);
        }
        return res;
    }
};
