class Solution {
private:
    bool checkship(std::vector<int>& weights, int days, int m){
        int curr{0};
        int count_d{1};
        for(int i = 0; i < weights.size(); i++){
            if(curr + weights[i] <= m){
                curr+=weights[i];
            }else{
                count_d++;
                curr = weights[i];
                if(count_d > days){
                    return false;
                }
            }
        }
        return true;
    }
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        if(weights.empty()) return 0;
        int l = *std::max_element(weights.begin(), weights.end());
        int r = std::accumulate(weights.begin(), weights.end(),0);
        while(l < r){
            int mid = l + (r-l)/2;
            bool check = checkship(weights, days, mid);
            if(check){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};
