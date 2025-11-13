//21. Merge Two Sorted Lists
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
//решение задачи - разворот списка
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //для нахождения головы новго списка создаем доп узел
        ListNode* head = nullptr;
        if(list1->val <= list2->val){
            head = list1;
            list1 = list1->next;
            head->next = nullptr;
        }else{
            head = list2;
            list2 = list2->next;
            head->next = nullptr;
        }
        //связываем его с новым списком
        ListNode* l3 = head;
        //создаем узелок который должен указывать на последний элемент
        ListNode* end = l3;
        //идем пока 2 списка не закончатся
        while(list1 != nullptr && list2 != nullptr){
            //сортируем элементы по возрастанию и добавляем в новый список
            if(list1->val <= list2->val){
                end->next = list1;
                //двигаемся дальше по списку
                list1 = list1->next;
            }else{
                end->next = list2;
                //двигаемся дальше по списку
                list2 = list2->next;
            }
            //двигаем дальше end, чтобы он указывал на конец списка
            end = end->next;
        }
        //для остатков
        if (list1 != nullptr) {
            end->next = list1;
        } else {
            end->next = list2;
        }
        //возвращаем результа
        return  l3;
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
