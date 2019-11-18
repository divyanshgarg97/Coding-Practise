class Solution {
public:
    //Approach 1: using max heap
    struct mycomparator{
        bool operator()(pair<int, string> a , pair<int, string> b ) {
            if( a.first > b.first)
                return false;
            if( a.first == b.first ) {
                if( a.second > b.second)
                    return true;
                else
                    return false;
            }
            return true;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> ump;
        int n = words.size(); 
        for( int i = 0 ; i< n;i++ ) {
            ump[words[i]]++;
        }
        priority_queue<pair<int, string>,vector<pair<int, string> > , mycomparator> pq;
        unordered_map<string, int> :: iterator it; 
        for( it = ump.begin() ; it!=ump.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }
        vector<string> ans; 
        for( int i = 0 ; i< k ;i++ ) {
            pair<int, string> p = pq.top(); 
            pq.pop(); 
            ans.push_back(p.second);
        }
        return ans;
        
        //appraoch 2 using min heap
        //approach 3 can be solved using bucket sort also like top k frequent elements
    }
};