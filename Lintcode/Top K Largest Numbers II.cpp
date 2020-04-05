class Solution {
    /*
    * @param k: An integer
    */
    private :
        int k;
        vector<int> v;
        priority_queue<int> pq;
    public:
        Solution(int k) {
            this->k = k;
        }
        void add(int num) {
            v.push_back(num);
            pq.push(num); // O(logn) time to for insertion in heap and it adjusts inside
        }
        vector<int> topk() {
            vector<int> ans;
            vector<int> store;
            for(int i = 0 ; i < k && !pq.empty(); i++) {
                ans.push_back(pq.top());
                store.push_back(pq.top()); //store all popped so that they can be stored later
                pq.pop(); //O(1) to pop and then O(logn) inside to adjust
            }
            for(int i = 0 ; i < store.size(); i++ ) 
                pq.push(store[i]); //O(logn) to adjust one more time
            return ans;
        }
};