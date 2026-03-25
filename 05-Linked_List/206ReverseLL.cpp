class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* curr = head;
        if(curr->next == nullptr){
            return head;
        }
        curr = curr->next;
        ListNode* prev = head;
        prev->next = nullptr;
        while(curr != nullptr){
                ListNode* second = curr->next;
                curr->next = prev;
                prev = curr;
                curr = second;
        }
        return prev;
    }
};
