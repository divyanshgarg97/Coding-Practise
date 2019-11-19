class Solution {
public:
    vector<string > ans; 
    void go( int a , int b , string s,int n ) {
        if( s.length() == 2*n ) {
            ans.push_back(s); 
            return;
        }
        if( a > 0 || a >=b ) {
            go( a -1 , b , s+'(', n  );
        }
        if( a < b ){
            go(a , b- 1, s+')' , n ) ;
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        go( n , n ,temp,n);
        return ans;
        
    }
};