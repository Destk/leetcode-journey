#include<iostream>
#include<vector>
#include<limits>
std::vector<int> twoSum(std::vector<int>& nums, int target){
    //ind - для сохранения результатов 
    int ind{},ind1{};
    //цикл для прохождения по nums
    for(int i = 0; i < nums.size()-1; i++){
        //второй цикл для того чтобы было легче искать нужные суммы
        for(int j = i+1; j < nums.size();j++){
            //если сумма элементов равна
            if(nums[i] + nums[j] == target){
                //сохраняем их индексы
                ind = i;
                ind1 = j;
            }
        }
    }
    return {ind, ind1};
}

void inputN(std::vector<int>& nums, int& target){
    //цикл для проверки
    do{
        std::cout<<"Введи кол-во элементов nums: \n";
        std::cin >> target;
        if(std::cin.fail()){
            //очистка флаги ошибок
            std::cin.clear();
            // очитска буфера ввода от 1000 до перевода на след строку
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Попробуйте ввести еще раз: ";}
    }while(std::cin.fail());
    //цикл для ввоада элементов
    for(int i = 0; i < target; i++){
        do{
            nums.push_back(int{});
            std::cin >> nums.back();
            if(std::cin.fail()){
                //очистка флаги ошибок
                std::cin.clear();
                // очитска буфера ввода от 1000 до перевода на след строку
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Попробуйте ввести еще раз: ";} 
                else {
                    // Ввод успешен - выходим из цикла
                    break;
    }
        }while(true);
    }
    //циклл для target
    do{
        std::cout<<"Введите target: \n";
        std::cin >> target;
        if(std::cin.fail()){
            //очистка флаги ошибок
            std::cin.clear();
            // очитска буфера ввода от 1000 до перевода на след строку
            std::cin.ignore(1000,'\n');
            std::cout<<"Попробуйте ввести еще раз: ";}
    }while(std::cin.fail());
}

void outputIn(std::vector<int>& Twosum){
    std::cout<<"TwoSum = [ ";
    for(int i = 0; i < Twosum.size(); i++){
        std::cout<<Twosum[i];
        if(i < Twosum.size()-1){
            std::cout<<", ";
        }
    }
    std::cout<<" ]\n";
}
int main(){
  char c;
  do{
  int target{};
  std::vector<int> nums;
  inputN(nums,target);
  std::vector<int> TwoSum = twoSum(nums,target);
  outputIn(TwoSum);
  std::cout<<"Продолжить (y/n) ?\n";
  std::cin>>c;
  }while(c == 'y' || c == 'Y');
  return 0;
}