
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        //using recursion
        if(head == NULL) return NULL; 
        head->next = removeElements(head->next , val);
        if( head->val == val){
            return head->next; 
        }
        return head; 
    }
};