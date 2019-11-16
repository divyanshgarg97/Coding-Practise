
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if( head == NULL) return head; 
        if( head->next == NULL) return head; 
        ListNode * slow , *fast ; 
        slow = head; 
        fast = head; 
        while( fast->next && fast->next->next){
            slow =slow->next; 
            fast = fast->next->next; 
        }
        if( fast->next) 
            return slow->next;
        return slow;
    
    }
    
    
    
};