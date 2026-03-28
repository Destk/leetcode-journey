class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head->next == nullptr || left == right) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        // 1. Дойти до узла перед left
        for(int i = 1; i < left; i++) {
            prev = prev->next;
        }
        
        // 2. Начать разворот
        ListNode* curr = prev->next;      // первый узел подсписка (станет хвостом)
        ListNode* tail = curr;            // запомнили хвост
        ListNode* prevRev = nullptr;
        
        for(int i = 0; i < right - left + 1; i++) {
            ListNode* tmp = curr->next;
            curr->next = prevRev;
            prevRev = curr;
            curr = tmp;
        }
        
        // 3. Соединить обратно
        prev->next = prevRev;    // prev указывает на новую голову подсписка
        tail->next = curr;       // хвост подсписка соединяем с остатком
        
        return dummy->next;
    }
};
