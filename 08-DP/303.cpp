class NumArray {
private:
    std::vector<int> pref{};
public:
    NumArray(vector<int>& nums) {
        pref.resize(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++){
            pref[i+1] = pref[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return pref[right+1] - pref[left];
    }
};
