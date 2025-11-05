// Solved problems 1493. Longest Subarray of 1's After Deleting One Element
#include<iostream>
#include<vector>
#include<algorithm>

//ввод в двоичный массив
void InputN(std::vector<int>& nums){
    std::cout<<"------ Программа: ,,Самый длинный подмассив из единиц после удаления одного элемента,, ------\n";
    do{
        int k{};
        std::cout<<"Введи кол-во элементов в nums\n";
        std::cin >> k;
        std::cout<<"Введите бинарные элементы (0/1)\n";
        for(int i = 0; i < k; i++){
            int j{};
            std::cin >> j;
            if(std::cin.fail() || (j != 0 && j != 1)){
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                i--;
                std::cout << "Ошибка! Введите 0 или 1: "; 
            }
            nums.push_back(j);
        }
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"ОШИБКА ВВОДА, попробуй ввести еще раз\n";
        }
    }while(std::cin.fail() || nums.empty());
}
//решение 1493. Longest Subarray of 1's After Deleting One Element
int longestSubarray(std::vector<int>& nums) {
        // левая граница, макс длина, счетчик для нулей
        int l{},maxLen{},countO{};
        //цикл 0 до конца
        for(size_t r = 0; r < nums.size(); r++){
            //если нашли ноль, увеличи счетчик
            if(nums[r] == 0){
                countO++;
            }
            //пока в окней больше одного 0, убираем 1 и двигаем левую границу
            while(countO > 1){
                if(nums[l] == 0){
                    countO--;
                }
                l++;
            }
            //по формуле высчитываем текущую длину
            int currLen = r - l;
            //обновляем максимум
            maxLen = std::max(maxLen,currLen);
        }
        return maxLen;
    }
//вывод результата
void OutputR(int r){
    std::cout<<"Самый длинный подмассив из единиц после удаления одного элемента: " << r <<'\n';
}
int main(){
    char c{};
    do{
        //подготовка для данных
        std::vector<int> nums;
        int r{};
        //ввод
        InputN(nums);
        //решение и сохранение результата
        r = longestSubarray(nums);
        //вывод
        OutputR(r);
        //очищаем массив
        nums.clear();
        //для продолжения работы
        std::cout<<"Продолжить? (y/n)\n";
        std::cin >> c;
        std::cin.ignore(10000,'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}