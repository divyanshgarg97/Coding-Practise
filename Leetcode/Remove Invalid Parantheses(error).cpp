class Solution {
public: 
    //it is showing heap buffer overflow ,dont know what is the problem
    int n; 
    void recur( string s , int l , int r , int i , string temp , int removed,vector<vector<string>> &check) {
        if( i == s.length() && l == 0 && r == 0) {
            check[removed].push_back(temp); 
            return; 
        }
        if(l < 0) return ;
        if( s[i] =='('){
            //take 
            recur( s, l + 1, r ,i + 1, temp + '(', removed,check); 
            //dont take
            recur( s , l , r , i+ 1, temp, removed + 1,check); 
            
        }
        else if( s[i] ==')'){
            //take only if earlier some ( exists
            if( l > 0) {
                //take
                recur ( s , l -1 , r , i + 1 , temp + ')' , removed,check);
                //dont take
                recur( s , l , r , i + 1, temp, removed + 1,check); 
            }
            else{
                //cannot take
                recur( s , l , r , i + 1, temp , removed+ 1,check); 
            }
        }
        else{
            //some alphabet
            recur( s , l , r , i + 1, temp + s[i] , removed,check);
        
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans; 
        n = s.length() ; 
        if( n == 0 || n == 1) {
            return ans; 
        }
        vector<vector<string> > check(n+1);
        int removed = 0 ; 
        string temp; 
        recur(s ,0 , 0 , 0 , temp, removed,check);
        int flag = 0 ; 
        cout<< "done";
        for( int i = 0 ; i < n+1 ;i++){
            for( int j = 0 ; j< check[i].size(); j++ ) { 
                ans.push_back(check[i][j]);
            }
        }
        return ans;
    }
};