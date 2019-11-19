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
        /*approach1 : using length
        //time :-O(m+ n) 
        //space :-O(1) constant
        ListNode * ptr1 = headA ; 
        ListNode * ptr2 = headB; 
        int m = 0 ; 
        while(ptr1){
            ptr1= ptr1->next;
            m++;
        }
        int n = 0 ; 
        while( ptr2){
            ptr2= ptr2->next; 
            n++;
        }
        if( m > n ){
            ptr1 = headA; 
            while(m - n > 0) {
                ptr1 = ptr1->next; 
                m --; 
            }
            ptr2 = headB; 
            while(ptr2){
                if( ptr1 == ptr2) 
                    return ptr1; 
                else{
                    ptr1= ptr1->next; 
                    ptr2 = ptr2->next;
                }
            }
        }
        else if( m <= n ){
            ptr2 = headB; 
            while(n - m > 0) {
                ptr2 = ptr2->next; 
                n --; 
            }
            ptr1 = headA; 
            while(ptr2){
                if( ptr1 == ptr2) 
                    return ptr1; 
                else{
                    ptr1= ptr1->next; 
                    ptr2 = ptr2->next;
                }
            }
        }
        return NULL;
        */
        //approach 2 :- we dont need length
        ListNode * ptr1= headA; 
        ListNode * ptr2 = headB;
        if( headA == NULL || headB == NULL ) 
            return NULL;
        while(ptr1 !=ptr2) {
            if( ptr1 == NULL){
                ptr1 = headB; 
            }
            if( ptr2 ==NULL) {
                ptr2 = headA; 
            }
            if( ptr1 == ptr2) 
                return ptr1;
            ptr1 = ptr1 ->next; 
            ptr2 = ptr2->next;
        }
        return ptr1;
        
    }
};