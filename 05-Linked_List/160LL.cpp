/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* currA = headA;
    ListNode* currB = headB;
    
    while(currA != currB){  // ← ИЗМЕНИТЬ УСЛОВИЕ ЦИКЛА
        // Двигаем указатели с переключением
        currA = (currA == nullptr) ? headB : currA->next;
        currB = (currB == nullptr) ? headA : currB->next;
    }
    
    return currA;  // вернёт или узел пересечения, или nullptr
}
};