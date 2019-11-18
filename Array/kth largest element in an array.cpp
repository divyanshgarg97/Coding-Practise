class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*Approach1 Time:-O(nlogn)(making) + O(klogn)(removing)=O(nlogn)
                    space = O(n)
        priority_queue<int> pq; 
        for( int i = 0 ; i < nums.size() ; i++ ) {
            pq.push(nums[i]);
        }
        for( int i = 0 ; i < k -1; i++ ) 
            pq.pop();
        return pq.top();
        */
        
        
        //Approach2 :-time O(nlogk)(making) + O(nlogk)(removing) = O(nlogk)
        //            space = O(k)
        //largest so using min heap to discard extra values into it
        
        priority_queue<int, vector<int> , greater<int> > pq; 
        for( int i = 0 ; i < nums.size(); i ++ ) {
            pq.push(nums[i]);
            if( pq.size() > k ) {
                pq.pop();
            }
        }
        return pq.top();
        
    }
};