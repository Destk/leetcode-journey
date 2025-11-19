#include<iostream>
#include<limits>
//структура связанного списка
struct ListNode{
    int val{};
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

//решение
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow;
        ListNode* reversL = nullptr;
        ListNode* prev = nullptr;
        while (mid != nullptr) {
            ListNode* next = mid->next;  // сохранили следующий
            mid->next = prev;            // заставили текущий указывать на предыдущий
            prev = mid;                  // передвинули prev
            mid = next;                  // передвинули mid
        }
        while(prev != nullptr){
            if(head->val != prev->val){
                return false;
            }
            head=head->next;
            slow = slow->next;
        }
        return true;
    }

//основная функция
int main(){
    char c{};
    do{

        //продолжить
        std::cout<<"Продолжить? (y/n): \n";
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}