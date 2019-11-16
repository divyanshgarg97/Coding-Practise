class Solution {
public:
    bool hasCycle(ListNode *head) {
        if( head == NULL|| head->next ==NULL) 
            return false; 
        ListNode * fast = head->next; 
        ListNode * slow = head; 
        while(fast->next && fast->next->next){
            if( slow == fast ) {
                return true;
            }
            slow = slow->next; 
            fast = fast ->next->next; 
        }
        return false;
    }
};