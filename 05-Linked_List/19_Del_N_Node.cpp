#include<iostream>
#include<limits>
//структура для создания листа
struct ListNode{
    int val{};
    ListNode*next;
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};
//вывод инфу о программе и n
void PrintIN(int& n){
    std::cout<<"Программа об удаление N-го узла из конца списка\n";\
    std::cout<<"Введите n: ";
    std::cin>>n;
    if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"Ошибка ввода, попробуйте еще раз\n";
    }
    std::cout<<'\n';
}
//ввод в список
ListNode* InputL(){
    int x{};
    std::cout<<"Введите кол-во значений в список: ";
    std::cin>>x;
    if (x == 0) {
    std::cout << "Создан пустой список\n";
    return nullptr;
    }
    if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"Ошибка ввода, попробуйте еще раз\n";
    }
    std::cout<<"\n Введите значения: ";
    int y{};
    std::cin >> y;
    ListNode*curr = new ListNode(y);
    ListNode*head = curr;
    for(int i = 0; i < x-1; i++){
        std::cin >> y;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте еще раз\n";
            i--;
        }
        ListNode* node = new ListNode(y);
        curr->next = node;
        curr = curr->next;
    }
    return head;
}
//решение задачи
ListNode* removeNthFromEnd(ListNode* head, int n) {
        //инициализаяция нужных узлов(фиктивный, черепаха, заяц)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        //определяем позицию для зайца
        for(int i = 0; i <n+1;i++){
            if(fast != nullptr ){
                fast = fast->next;
            }
            else{
                return head;
            }
        }
        //заставляем бежать пока заяц не добежал до финиша||конца
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        //теперь когда заяц у финиша, черепаха находится перед тем что нужно удалить, поэтому удаляем это
        ListNode* toDel = slow->next;
        slow->next = slow->next->next;
        delete toDel;
        //возвращаем то что у нас получилось
        return dummy->next;
}
//вывод получившегося списка
void PrintList(ListNode* head){
    std::cout<<"Получившийся список: \n";
    while(head != nullptr){
        std::cout<<head->val;
        if(head->next!=nullptr){
            std::cout<<" -> ";
        }
        head = head->next;
    }
    std::cout<<" -> NULL\n";
}
//Очитска памяти
void Del(ListNode* head){
    while(head != nullptr){
        ListNode* t = head;
        head = head->next;
        delete t;
    }
}
//основная функция 
int main(){
    char c{};
    do{
        ListNode*head;
        int n{};
        PrintIN(n);
        head = InputL();
        PrintList(head);
        head = removeNthFromEnd(head, n);
        PrintList(head);
        Del(head);
        std::cout << "Продолжить? (y/n): ";
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}