#include <iostream>
#include <vector>

class Solution {
private:
	std::vector<int> piles{};
	int h{};
public:

    int minEatingSpeed(std::vector<int>& piles, int h) {
        if(piles.empty()) return 0;
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        long long hh{};
        while(l < r){
            int mid = l + (r - l)/2;
            hh = 0;
            for(int i = 0; i < piles.size();i++){
                hh+= (piles[i] + mid - 1)/mid;
            }
            if(hh > h){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};

int main(){
    char s;
    do{
        
        std::cout<< "Продолжить? (y/n): \n";
        std::cin>> s;
        std::cin.ignore(10000,'\n');
    }while(s =='y' || s == 'Y');
    return 0;
}
