class Solution {
private:
    bool Bsearch(std::vector<int>& arr, int t, int skipind){
        int l = 0;
        int r = arr.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid] == t && mid != skipind){
                return true;
            }else if(arr[mid] < t){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return false;
    }
public:
    bool checkIfExist(std::vector<int>& arr) {
        if(arr.empty()) return false;
        std::sort(arr.begin(), arr.end());
        for(int j = 0; j < arr.size(); j++){
            int target = arr[j] * 2;
            if (Bsearch(arr, target, j)) {
            return true;
            }
        }
        return false;  
    }
};
