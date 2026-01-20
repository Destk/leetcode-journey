#include <iostream>
#include <vector>
#include <limits>
class Solution {
private:
    std::vector<std::vector<int>> matrix;
    int target;
public:
    Solution() : target(0), matrix() {};
    void setTarget(){
        bool x = true;
        while(x){
            std::cout<<"Введите target: ";
            int t{};
            std::cin >> t;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                continue;
            }else{
                std::cout<<"\n Target = " << t << '\n';
                target = t;
                x = false;
            }
        }
    }
    void setMaxtrix(){
        bool x = true;
        while(x){
            std::cout<<"Введите кол-во элементов в строке: ";
            int s{};
            std::cin >> s;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                continue;
            }
            std::cout<<"Введите кол-во элементов в столбце: ";
            int t{};
            std::cin >> t;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                continue;
            }else{
                matrix.assign(s, std::vector<int>(t));
                for(int i = 0; i < (int)matrix.size(); i++){
                    for(int j = 0; j < (int)matrix[0].size(); j++){
                        std::cout<<"\nВводите элемент в матрицу: ";
                        std::cin >> matrix[i][j];
                        if(std::cin.fail()){
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            std::cout<<"\nОшибка ввода, попробуйте ещё раз\n";
                            i--;
                            j--;
                            continue;
                        }
                    }
                }
                std::cout<<'\n';
                x = false;
            }
        }    
    }
    bool searchMatrix() {
        //1)Базовый случай если матрица пуста
        if(matrix.empty() || matrix[0].empty()) return false;
        //2)Границы для БП, где high(строки*столбцы)
        int low = 0;
        int high = (matrix.size()*matrix[0].size())-1;
        //3)цикл для БП
        while(low <= high){
            //4)Вычисляем mid
            int mid = low + (high-low)/2;
            int cols = matrix[0].size();  
            int row = mid / cols;         
            int col = mid % cols;         
            //5)Условия для БП
            if(matrix[row][col] > target){
                high = mid - 1;
            }else if(matrix[row][col] < target){
                low = mid + 1;
            }else{
                return true;
            }
        }
        //6)Если ничего не нашли, то false
        return false; 
    }

    void out(bool r){
        if(r == true){
            std::cout<<"Число target находится в матрице\n";
        }else{
            std::cout<<"Число target нет в матрице\n";
        }
    }
};

int main(){
    char stop{};
    std::cout<<"Программа по поиску числа в матрице\n";
    do{
        Solution p;
        p.setTarget();
        p.setMaxtrix();
        bool r = p.searchMatrix();
        p.out(r);
        std::cout<<"Продолжить? (y/n): ";
        std::cin>>stop;
        std::cout<<'\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(stop == 'y' || stop == 'Y');
    return 0;
}