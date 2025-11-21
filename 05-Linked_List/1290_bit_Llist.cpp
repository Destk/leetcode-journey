#include<iostream>
#include<limits>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* Input(){
    ListNode* node = nullptr;
    ListNode* head = nullptr;
    std::cout<<"Это программа для преобразования двоичного числа в связанном списке в целое число\n";
    
    do{
        std::cout<<"Сколько элементов будет в списке: \n";
        int x{};
        std::cin>>x;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
            continue;
        }

        std::cout<<"Введите " << x << " двоичных цифр (0 или 1) через пробел: \n";
        
        // Читаем все числа сразу
        for(int i = 0; i < x; i++){
            int y;
            std::cin >> y;
            
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Ошибка ввода, попробуйте ещё раз\n";
                i--;
                continue;
            }

            if(y != 0 && y != 1){
                std::cout<<"Ошибка: введите только 0 или 1\n";
                i--;
                continue;
            }

            // Создаем новый узел
            ListNode* newNode = new ListNode(y);
            
            if(head == nullptr){
                // Первый элемент
                head = newNode;
                node = head;
            } else {
                // Последующие элементы
                node->next = newNode;
                node = node->next;
            }
        }
        
    }while(std::cin.fail());
    
    return head;
}
   void PrintList(ListNode* head){
    ListNode* curr = head;
    while(curr != nullptr){
        if(curr != nullptr){
            std::cout<< curr->val << " -> ";
        }
        curr = curr->next;  
    }
    std::cout<<" -> NULL\n";
}

int getDecimalValue(ListNode* head) {
        if (head == nullptr) {
        return 0;
        }
        int r{0};
        ListNode* curr = head;
        while(curr != nullptr){
            if(curr != nullptr){
                r = r * 2+ curr->val;
            }
            curr = curr->next;
        }
        return r;
    }

void OutputR(int r){
    std::cout<<"Результат перевода 2->10 : " << r<<'\n';
}
void delList(ListNode* head){
    while(head != nullptr){
        ListNode* tmp = head;
        head=head->next;
        delete tmp;
    }
}
    int main(){
        char c{};
        do{
            ListNode* head = Input();
            PrintList(head);
            int r = getDecimalValue(head);
            OutputR(r);
            delList(head);
            std::cout<<"Продолжить? (y/n)\n";
            std::cin>> c;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }while(c == 'y' ||  c == 'Y');
        return 0;
    }