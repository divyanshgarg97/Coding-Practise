
//good one
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //recursion 
        if( head == NULL) return NULL; 
        if( head->next == NULL) return head;
        ListNode * newhead = head->next; 
        ListNode * third = newhead->next; 
        newhead->next = head; 
        head->next = swapPairs(third); 
        return newhead;
    }
};