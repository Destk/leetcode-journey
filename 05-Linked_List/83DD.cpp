    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* currlist = head;//связываем с головой
        while(currlist != nullptr && currlist->next != nullptr){
            if(currlist->val == currlist->next->val){
                currlist->next = currlist->next->next;
            }else{
                currlist = currlist->next;
            }
        }
        return head;
    }
