#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
private:
    bool checkproduct(std::vector<int>& quantities, int n, int mid){
        int total_r{0};
        for(auto el : quantities){
            total_r+=(el + mid - 1)/mid;
        }
        if(total_r > n) return false;
        return true;
    }
    std::vector<int> quantities{};
    int n{};
public:
    void inp(){
    	bool st{false};
	while(!st){
	   std::cout<<"Введите кол-во элементов в массиве: ";
	   int x{};
	   std::cin>>x;
	   if(std::cin.fail()){
	   	std::cin.clear();
		std::cin.ignore();
		std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
		continue;
	   }else{
	   	for(int i = 0; i < x; i++){
		    std::cout<<"\nВведите элемент: ";
		    int y{};
		    std::cin>>y;
		    if(std::cin.fail()){
                     std::cin.clear();
                     std::cin.ignore();
                     std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
    		        i--;
                    continue;
                  }
		    quantities.push_back(y);
		}
		std::cout<<"\nВведите кол-во магазинов: ";
		std::cin>>n;
		if(std::cin.fail()){
		   std::cin.clear();
		   std::cin.ignore();
		   std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
		   continue;
		}
		std::cout<<'\n';
		st = true;
	   }

	}
    }
    int minimizedMaximum(){
        if(quantities.empty() || n == 0) return 0;
        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());
        while(l < r){
            int mid = l + (r - l)/2;
            if(!checkproduct(quantities,n,mid)){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
    void out(const int r){
    	std::cout<<"Минимальное количество товаров, которое может быть поставлено в любой магазин: " << r<<'\n';
    }
};


int main(){
    char s{};
    std::cout<<"Минимальное количество товаров, поставляемых в любой магазин\n";
    do{
	Solution p;
	p.inp();
	int r = p.minimizedMaximum();
	p.out(r);
    	std::cout<<"Продолжить? (y/n): ";
	std::cin>>s;
	std::cin.ignore();
	std::cout<<'\n';
    }while(s == 'y' || s == 'Y');
return 0;
}
