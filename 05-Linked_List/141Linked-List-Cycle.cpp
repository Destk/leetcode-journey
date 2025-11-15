//141. Цикл в связанном списке
#include<iostream>
#include<limits>
//структура связанного списка
struct ListNode{
    //значение и указатель на следующий элемент
    int val = 0;
    ListNode* next;
    //конструктор по умолчанию
    ListNode(int x) : val(x), next(nullptr) {}
    //конструктор с значениями
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//функция для удаления списка
void deleteL(ListNode* head){
    ListNode* cuur = head;
    while(cuur != nullptr){
        ListNode* next = cuur->next;
        delete cuur;
        cuur = next;
    }
}
//функция ввода кол-ва элементов и ознакомление с программой
void InputN(int& n){
    std::cout<<"Это программа по поиску цикла в связанном списке\n";
    do{
        std::cout<<"Введи кол-во элементов в списке: \n";
        std::cin>>n;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё\n";
        }
    }while(std::cin.fail());
}
//функция создание в листа
ListNode* CreatList(int n){
    int j{};
    do{
    std::cout<<"Введите эелементы: \n";
    std::cin>>j;
    if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ошибка ввода, попробуйте ещё\n";
        }
    }while(std::cin.fail());
    ListNode* head = new ListNode(j);
    ListNode* end = head;
    for(int i = 0; i < n-1; i++){
        int k{};
        std::cin>>k;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            i--;
            continue;
        }
        ListNode* currEl = new ListNode(k);
        end->next = currEl;
        end = currEl;
    }
    return head;
}
//функция отображения списка
void PrintList(ListNode* head){
    ListNode* curr = head;
    std::cout<<"Получившийся список: \n";
    //пока не дошли до конца
    while(curr != nullptr){
        std::cout<<curr->val;
        //если не дошли до конца то перед каждым новым элементов выводим
        if(curr->next != nullptr){
            std::cout<< " -> ";
        }
        //двигаемся дальше
        curr = curr->next;
    }
    std::cout<<" -> NULL\n";
}
//функция для решения задачи
bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        //2 указателя для бега (черепаха, заяц)
        ListNode* slow = head;
        ListNode* fast = head;
        //пока заяц не добежал до конца
        while(fast != nullptr && fast->next != nullptr){
            //заставляем бежать наших зверей
            slow = slow->next;
            fast = fast->next->next;
            //если заяц догнал черепаху то цикл есть
            if(fast == slow){
                return true;
            }
        }
        //если заяц пробежал до nullptr, то цикла нет
        return false;
}
//функция вывода

void OutputR(bool r){
    if( r == true){
        std::cout<<"В списке есть цикл " << std::boolalpha << r<<'\n';
    }else{
         std::cout<<"В списке нет цикла " << std::boolalpha << r<<'\n';
    }
}

int main(){
    char c{};
    do{
        //1) - вывод инфы о программе и запрос кол-во элементов
        int n{};
        InputN(n);
        //создаем лист
        ListNode* head = CreatList(n);
        //выводим получившийся лист 
        PrintList(head);
        //для решения задачи
        bool r = hasCycle(head);
        //выводим результат
        OutputR(r);
        //удаляем лист - то есть чистим память
        deleteL(head);
        //продолжение
        std::cout<<"Продолжить? (y/n)\n";
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
}