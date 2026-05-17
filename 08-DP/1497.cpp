class Solution {
public:
    bool canArrange(std::vector<int>& arr, int k) {
        std::vector<int> pref(k, 0);
        for(int i = 0; i < arr.size(); i++){
            int tmp = ((arr[i] % k) + k) % k;
            pref[tmp]++;
        }    
        if(pref[0] % 2 != 0) return false;
        for(int i = 1; i < k/2; i++){
            if(i == k-1 && pref[0] % 2 == 0){
                return true;
            }
        }
        for (int i = 1; i < k; i++) {
            if (i == k - i) {  // k чётное, i = k/2
                if (pref[i] % 2 != 0) return false;
            } else {
                if (pref[i] != pref[k - i]) return false;
            }
        }
        return true;
    }
};