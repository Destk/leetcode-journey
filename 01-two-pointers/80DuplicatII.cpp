#include <iostream>
#include <vector>

class Solution {
private:
	std::vector<int> nums{};
public:
    void inp(){
    	bool s{false};
	while(!s){
		std::cout<<"Введите кол-во элементов: ";
		int x{};
		std::cin>>x;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore();
			std::cout<<"\nОшибка ввода, попробуйте ещё раз!!!\n";
			continue;
		}else{
			for(int i = 0; i < x; i++){
				std::cout<<"\nВведит элемент: ";
				int y{};
				std::cin>>y;
				if(std::cin.fail()){
                        		std::cin.clear();
                        		std::cin.ignore();
                        		std::cout<<"\nОшибка ввода, попробуйте ещё раз!!!\n";
					i--;
                        		continue;
                		}
				nums.push_back(y);
			}
			std::cout<<'\n';
			s = true;
		}
	}
    }
    int removeDuplicates() {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return 1;
        int slow{2};
        for(int fast = 2; fast < nums.size(); fast++){
            if(nums[fast] != nums[slow-2]){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
    void out(int r){
    	std::cout<<"Кол-уникальных элементов в массиве находится до позиции " << r << '\n';
    }
};

int main(){
char s{};
do{
	Solution sol;
	sol.inp();
	int r = sol.removeDuplicates();
	sol.out(r);
	std::cout<<"Продолжить? (y/n): ";
	std::cin>>s;
	std::cout<<'\n';
}while(s == 'y' || s == 'Y');
return 0;
}
