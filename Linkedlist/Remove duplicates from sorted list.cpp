
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == NULL || head->next == NULL ) 
            return head; 
        ListNode * curr = head;
        ListNode * temp = head->next; 
        while(temp!=NULL) {
            if( curr->val == temp->val) {
                temp = temp->next; 
            }
            else{
                curr->next = temp ; 
                curr = curr->next; 
                temp=temp->next;
            }
        }
        curr->next = NULL;//important
        return head;
    }
};