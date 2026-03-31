class Solution {
public:
    char nextGreatestLetter(std::vector<char>& letters, char target) {
        if(letters.empty()) return '\n';
        int low = 0;
        int high = letters.size() - 1;
        char res = letters[0];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(letters[mid] > target){
                res = letters[mid];
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
};
