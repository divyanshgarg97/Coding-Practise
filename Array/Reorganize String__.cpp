class Solution {
public:
    struct mycomparator{
        bool operator()(pair<int,char> a , pair<int, char> b) {
            if( a.first > b.first)
                return false; 
            return true;
        }
    };
    string reorganizeString(string S) {
        //good one
        int n = S.length() ; 
        if( n == 0 || n == 1 ) return S; 
        unordered_map<char , int > ump; 
        for( int i = 0 ; i < n; i++ ) {
            ump[S[i]]++;
        }
        priority_queue<pair<int, char > , vector<pair<int, char> > , mycomparator > pq; 
        unordered_map<char, int> ::iterator it; 
        for( it = ump.begin() ; it!=ump.end(); it++) {
            pq.push(make_pair(it->second ,it->first)); 
        }
        string ans, notdone;
        pair<int, char> prev,curr , next;//curr;
        ans = (pq.top()).second;
        curr = pq.top();
        pq.pop();
        curr.first = curr.first - 1; 
        if( curr.first > 0)
            pq.push(curr);
        prev = curr; 
        cout<< ans;
        while(ans.length() < n ) {
            curr = pq.top() ;
            pq.pop(); 
            //curr is same as prev; 
            if( curr.second == prev.second){
                //get next one
                if( pq.size() ==0) //next does not exist
                    return notdone;
                else{
                    //next exist
                    next = pq.top() ; 
                    pq.pop(); 
                    ans = ans + next.second;
                    next.first = next.first - 1; 
                    if( next.first > 0) 
                        pq.push(next);
                    prev = next; 
                    pq.push(curr);
                }
            }
            else{
                ans = ans + curr.second;
                curr.first = curr.first -1; 
                if( curr.first > 0) 
                    pq.push(curr);
                prev = curr;
            }
        }
        
        return ans;
    }
};