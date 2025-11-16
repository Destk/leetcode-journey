#include<iostream>
#include<limits>
//структура списка
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};
//функция запроса кол-ва элементов в списке + вывод инфу
void PrintInfo(int& n){
    std::cout<<"Это программа по поиску середины связанного списка\n";
    do{
    std::cout<<"Введите кол-во элементов в списке: \n";
    std::cin>>n;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"ОШИБКА ВВОДА, ПОПРОБУЙТЕ ЕЩЁ РАЗ\n";
    }
}while(std::cin.fail());
}
//функция ввода
ListNode* Input(int n){
    int x{};
    do{
    std::cout<<"Введите элементы списка: \n";
    std::cin>>x;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"ОШИБКА ВВОДА, ПОПРОБУЙТЕ ЕЩЁ РАЗ\n";
    }
}while(std::cin.fail());
    ListNode* curr = new ListNode(x);
    ListNode* end = curr;
    for(int i = 0; i < n-1; i++){
        std::cin>> x;
        if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"ОШИБКА ВВОДА, ПОПРОБУЙТЕ ЕЩЁ РАЗ\n";
        i--;
        }
        ListNode* node = new ListNode(x);
        end->next = node;
        end = end->next;
    }
    return curr;
}
//вывод получившегося списка
void PrintList(ListNode* head){
    ListNode*curr = head;
    while(curr != nullptr){
        std::cout<<curr->val;
        if(curr->next != nullptr){
            std::cout<<" -> ";
        }
        curr = curr->next;
    }
    std::cout<<" -> NULL\n";
}
//нахождение середины
ListNode* middleNode(ListNode* head) {
    //1) инициализируем зайца и черепаху
    ListNode* rabbit = head;
    ListNode* turtle = head;
    //звапускаем эстафету пока заяц не победил
    while(rabbit != nullptr && rabbit->next != nullptr){
        //запускаем животных, заяц с шагом 2, черепаха с шагом 1
        turtle = turtle->next;
        rabbit = rabbit->next->next;
    }
    //когда заяц добежит до финиша, черепаха будет на середине забега
    return turtle;

}
//основная функция
int main(){
    char c{};
    do{
        //инициализация нужных элементов
        int n{};
        ListNode* head;
        //ввод
        PrintInfo(n);
        head = Input(n);
        PrintList(head);
        //решение
        ListNode* result = middleNode(head);
        //вывод результата
        std::cout<<"Середина списка: \n";
        PrintList(result);
        //продолжение
        std::cout<<"Продолжить? (y/n)\n";
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}