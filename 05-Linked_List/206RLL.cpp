//206 Linked List
#include<iostream>
#include<limits>

//структура для связанного списка
struct ListNode{
    int val;
    ListNode* next;
    //конструктор связного списка, начальный элемент и след
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//ввод в список (СОЗДАЁТ НОВЫЙ список)
ListNode* Input(){
    std::cout<<"Программа на обратный связанный список\n";
    int k{};
    do{
        std::cout<<"Сколько элементов будет: \n";
        std::cin>>k;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте еще раз\n";
        }
    }while(std::cin.fail());
    
    std::cout<<"Введите первое значение: \n";
    int n{};
    do{
        std::cin >> n;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте еще раз\n";
        }
    }while(std::cin.fail());
    
    // Создаём голову списка
    ListNode* head = new ListNode(n);
    ListNode* current = head;  
    
    // Добавляем остальные элементы
    for(int i = 0; i < k; i++){
        std::cout << "Введите значение элемента " << i + 1 << ": ";
        int value;
        do {
            std::cin >> value;
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода, попробуйте еще раз: ";
            }
        } while(std::cin.fail());
        
        // Создаём новый узел и привязываем в конец
        current->next = new ListNode(value);
        current = current->next;
    }
    
    return head;  // возвращаем созданный список
}

//решение задачи - разворот списка
ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    
    while(curr != nullptr){
        ListNode* next_temp = curr->next;  // сохраняем следующий
        curr->next = prev;                 // разворачиваем указатель
        prev = curr;                       // двигаем предыдущий
        curr = next_temp;                  // двигаем текущий
    }
    
    return prev;  // возвращаем новую голову
}

//вывод списка
void Output(ListNode* head) {
    ListNode* current = head;  // сохраняем оригинальный указатель
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr)  
            std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

//основная функция 
int main(){
    char c{};
    do{
        // 1. Создаём список
        ListNode* head = Input();
        
        // 2. Выводим исходный список
        std::cout << "Исходный список: ";
        Output(head);
        
        // 3. Разворачиваем список
        ListNode* reversed = reverseList(head);
        
        // 4. Выводим результат
        std::cout << "Развёрнутый список: ";
        Output(reversed);
        
        // 5. Продолжение
        std::cout<<"Продолжить? (y/n)\n";
        std::cin>>c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        
    }while(c == 'Y' || c == 'y');
    
    return 0;
}