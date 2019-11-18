class Solution {
public:
    //approach 1 :-using max heap
    struct mycomparator{
        bool operator() (const pair<int , char > &a ,const pair< int, char > &b ) {
            if( a.first > b.first)
                return false; 
            else if( a.first == b.first){
                if(a.second > b.second){
                    return true;
                }
                else
                    return false;
            }
            return true;
        }
    };
    string frequencySort(string s) {
        unordered_map<char , int > ump; 
        int n = s.length() ; 
        for( int i = 0 ; i < n;i++ ) {
            ump[s[i]] ++;
        }
        priority_queue<pair<int , char> , vector<pair<int, char > > , mycomparator> pq; 
        unordered_map<char , int> :: iterator it; 
        for( it = ump.begin() ; it!=ump.end(); it++ ) {
            pq.push(make_pair(it->second, it->first));
        }
        string ans;
        while( pq.size() > 0 ) {
            for( int i = 0 ; i < pq.top().first ; ++i ) {
                ans.push_back( pq.top().second );
            }
            pq.pop();
        }
        return ans;
    }
    //approach 2 bucket sort
    /*string frequencySort(string s){
        unordered_map<char , int > ump; 
        int n = s.length() ; 
        for( int i = 0 ; i < n;i++ ) {
            ump[s[i]] ++;
        }
        vector<vector<char> > bucket(n+ 1) ; 
        unordered_map<char , int > :: iterator it;
        for( it = ump.begin() ; it !=ump.end() ; it++) {
            bucket[it->second].push_back(it->first);
        }
        string ans; 
        for( int i = n ; i>=0; i--){
            sort(bucket[i].begin(), bucket[i].end());
            for( int j = 0 ;j < bucket[i].size() ;j++ ) {
                int temp = i ; 
                while( temp>0){
                    ans = ans + bucket[i][j];
                    temp--;
                }
            }
        }
        return ans;
    }*/
    
};