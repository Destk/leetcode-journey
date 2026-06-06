class Solution {
public:
    void quicksort(std::vector<int>& nums, int l, int r){
        int p = nums[l + (r-l)/2];
        int i = l;
        int j = r;

        while( i <= j){
            while(nums[i] < p) i++;
            while(nums[j] > p) j--;

            if(i<=j){
                std::swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        if(l < j) quicksort(nums,l, j);
        if(r > i) quicksort(nums,i, r);
    }
    std::vector<int> sortArray(std::vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
};
