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
    /*
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    //APPROACH 1    
        //simple approach using priority_queue
        //time complexity = O(n)(for travesing lists) + O(n*logn)(for making heap) + O(n*logn) (for removing)
        // space complexity = O(n) 
        priority_queue<int,vector<int> , greater<int> > pq; 
        if( lists.size() == 0) return NULL ; 
        for(int i = 0; i < lists.size() ; i++ ) {
            ListNode * temp = lists[i];
            while( temp){
                pq.push(temp->val); 
                temp = temp->next;
            }
        }
        if(pq.size() == 0) return NULL; 
        else{
            ListNode * answer = new ListNode ( pq.top() ) ; 
            pq.pop();
            ListNode * temp2 = answer; 
            while(pq.size() ) {
                temp2->next= new ListNode (pq.top());
                pq.pop() ; 
                temp2= temp2->next;
            }
            return answer;
        }
        return NULL; 
    }*/
    //APPROACH 2
    //which make use that already lists are sorted row wise; 
    //priority_queue only but only k elements at a time
    struct mycomparator{
        bool operator() ( pair<int, ListNode * > a , pair<int, ListNode*> b ) {
            if( a.first < b.first)
                return false; 
            return true;
        }  
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode* > ,vector<pair<int, ListNode * > > , mycomparator > pq; 
        if( lists.size() == 0) return NULL ;
        for( int i = 0 ; i< lists.size() ; i++ ) {
            ListNode * temp  = lists[i];
            if(temp!=NULL) {
                pq.push(make_pair(temp->val , temp));
            }
        }
        ListNode * headanswer = NULL;
        if( pq.empty()) return NULL; 
        pair<int, ListNode * > w = pq.top() ; 
        headanswer = new ListNode(w.first);
        pq.pop();
        if(w.second->next)
            pq.push(make_pair((w.second)->next->val , (w.second)->next));
        ListNode * temp = headanswer;
        while(!pq.empty()){
            pair<int, ListNode * > s = pq.top() ;
            temp->next = new ListNode(s.first); 
            temp=temp->next;
            pq.pop();
            if(s.second ->next)
                pq.push(make_pair((s.second)->next->val , (s.second)->next));
        }
        return headanswer;
        //Time Complexity :-O(n)(to traverse) + O(nlogk)(for priorityqueue making )
        //space complexity :-O(k)
    }
};