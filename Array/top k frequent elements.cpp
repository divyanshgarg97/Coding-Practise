class Solution {
public:
   // vector<int> topKFrequent(vector<int>& nums, int k) {
        //Approach 1: using max heap
        //time :- O(n)(making map) + O(n * logn)(making heap by putting values one by one) + O(k*log(n-k)) removing k values from heap and log(n-k) for adjusting everytime) = O(nlogn)
        //space:- O(n)
        /*unordered_map<int, int> ump; 
        int n = nums.size();
        for( int i = 0 ; i< n;i++) {
            ump[nums[i]]++;
        }
        priority_queue<pair<int, int> > pq;
        for( auto i = ump.begin() ;i!=ump.end();i++){
            pq.push(make_pair(i->second, i->first)); 
    
        }
        vector<int> ans;
        pair<int, int> p;
        for( int i = 0 ; i < k ;i++ ) {
            p = pq.top(); 
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
        */
        
        /*
        //approach2: using min heap
        //space :- O(k)
        
    struct mycomparator{
        bool operator()(pair<int, int > a , pair<int, int> b ) {
            if( a.first > b.first)
                return true;
            return false;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int n = nums.size(); 
        for( int i = 0 ; i< n ;i++) {
            ump[nums[i]]++;
        }
        priority_queue<pair<int, int> , vector<pair<int , int> > , mycomparator> pq; 
        unordered_map<int,int> :: iterator ii;
        for( ii = ump.begin() ;ii!=ump.end();ii++ ) {
            pq.push(make_pair(ii->second, ii->first));
            if( pq.size()> k) {
                pq.pop();
            }
        }
        vector<int> ans; 
        for( int i = 0 ; i< k ;i++ ){
            pair<int, int> p = pq.top();
            ans.push_back(p.second);
            pq.pop();
        }
        return ans;
        */
    //approach 3 : using bucket sort
    //time :-O(n)(map) + O(n)(bucket making) + O(n)(for finding as it will be traversed only n times) = O(n)
    //space :-O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int n = nums.size(); 
        for( int i = 0 ; i< n ;i++) {
            ump[nums[i]]++;//O(n)
        }
        vector<vector<int> > bucket(nums.size() + 1); // need to define size initially //+1 as if all same hence range between 0 to nums.size() i.e n + 1
        unordered_map<int, int> :: iterator it;
        for( it = ump.begin() ; it!=ump.end(); it++) {
            bucket[it->second].push_back(it->first);//O(n) size
        }
        vector<int> ans;
        for( int i = nums.size() ; i >=0; i--) {
            for( int j = 0 ;j < bucket[i].size() ;j++){
                ans.push_back(bucket[i][j]);
                if( ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};