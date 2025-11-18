#include<iostream>
#include<limits>
//структура для связанного списка
struct ListNode{
    int val{};
    ListNode* next;
    ListNode(int x) : val(x),next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};
//решение задач
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int s{};
    ListNode* l3;
    ListNode* dummy = new ListNode(0);
    l3 = dummy;
    while(l1 != nullptr || l2 != nullptr || s != 0){
        int val1{},val2{};
        if(l1 != nullptr){
            val1 = l1->val;
        }if(l2 != nullptr){
            val2 = l2->val;
        }
        s = val1 + val2 + s;
        if(l1 != nullptr && l2 != nullptr){
            l1 = l1->next;
            l2 = l2->next;
        }else if(l1 != nullptr){
            l1 = l1->next;
        }else if(l2 != nullptr){
            l2 = l2->next;
        }
        l3->next = new ListNode(s%10);
        l3 = l3->next;
        s = s/ 10;
    }
    return dummy->next;
}

//основная функция
int main(){
    char c{};
    do{
        //продолжение
        std::cout<<"Продолжить? (y/n)\n";
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c =='Y');
    return 0;
}