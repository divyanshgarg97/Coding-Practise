class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        // prefix sum solution
        // count occurence of odd values upto every index n 
        //prefix that we need here is complete previous substr data + new data
        int n = s.length(); 
        vector<vector<int> > pre(n+1,vector<int> (26,0)); 
        for( int i = 0 ; i < n ;i++) {
            pre[i+1] = pre[i];
            pre[i+1][s[i] - 'a']++;
        }
        vector<bool> ans;
        for(int i = 0 ; i < queries.size();i++){
            int val = 0; 
            for( int j = 0 ;j < 26; j ++ ) {
                int temp = pre[queries[i][1] + 1][j] - pre[queries[i][0]][j];
                if( temp % 2 !=0) 
                    val++;
            }
            if( val / 2 <= queries[i][2]) 
                ans.push_back(true);
            else 
                ans.push_back(false);
        }
        return ans;
        
    }
};