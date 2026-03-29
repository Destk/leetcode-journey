#include <iostream>
#include <vector>

class Solution {
private:
	std::vector<int> nums{};
public:
    void inp(){
	bool stop{false};
	while(!stop){
    		std::cout<<"Введите кол-во элементов в массиве: ";
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
				if(std::cin.fail()){
                        		std::cin.clear();
                        		std::cin.ignore();
                        		std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
								i--;
                        		continue;
				}
				nums.push_back(y);
			}
				std::cout<<'\n';
				stop = true;
				if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout<<"\nОшибка ввода, попробуйте ещё раз!\n";
                        continue;
                }
		}
	}
}
    void sortColors() {
        if(nums.empty()) return ;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            int min_ind{i};
            for(int j = i + 1; j < n; j++){
                if(nums[j] < nums[min_ind]){
                    min_ind = j;
                }
            }
            std::swap(nums[i], nums[min_ind]);
        }
    }
    void out(){
    	std::cout<<"Текущий массив: ";
	for(int i : nums){
		std::cout<<i << " ";
	}
	std::cout<<'\n';
    }
};

int main(){
	char stop{};
	std::cout<<"Сортировка по цветам\n Белый - 0\n Красный - 1\n Синий - 2\n";
	do{
		Solution r;
		r.inp();
		r.out();
      	r.sortColors();
		std::cout<<"После сортировки\n";
		r.out();
		std::cout<<"Продолжить? (y/n): ";
		std::cin>>stop;
		std::cin.ignore();
		std::cout<<'\n';
	}while(stop == 'y' || stop == 'Y');
	return 0;
};
