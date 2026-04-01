#include <iostream>
#include <vector>

class Solution {
private:
    std::vector<int> nums{};
public:
    void inp(){
        bool stop{false};
        while(!stop){
            std::cout<<"Введите кол-во элементов в отсортиоованном массиве: ";
            int x{};
            std::cin>>x;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                continue;
            }else{
                for(int i = 0; i < x; i++){
                    std::cout<<"\nВведите элемент: ";
                    int y{};
                    std::cin>>y;
                    nums.push_back(y);
                }
                std::cout<<'\n';
                stop = true;
            }
        }
    }
    int findMin() {
        if(nums.empty()) return 0;
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            // 1l 2 3m 4 5r
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            // 3l 4 5m 1 2r
            else{
                r = mid;
            }
        }
        return nums[l];
    }
    void out(int r){
        std::cout<<"минимальное значение в отсортированном массиве с поворотом: "<< r << '\n';
    }
};

int main(){
    char stop{};
    do{
	Solution s;
	s.inp();
	int r = s.findMin();
	s.out(r);
    	std::cout<<"Продолжить? (y/n): ";
	std::cin>>stop;
	std::cin.ignore();
	std::cout<<'\n';
    }while(stop == 'y' || stop == 'Y');
    return 0;
}
