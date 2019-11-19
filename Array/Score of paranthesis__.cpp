class Solution {
public:
    int scoreOfParentheses(string S) {
        string s = S; 
        if( s.length() == 0)
            return 0; 
        int ans =0 ; 
        int l = 0 ; 
        int i = 0 ; 
        int n = s.length() ; 
        while( i < n){
            if( s[i]=='('){
                l++; 
            }
            else {
                if( s[i-1]=='('){

                    ans = ans + (1<< (l-1)); 
                }
                l--;
            }
            i++;
        }
        return ans;
        
        
        
        
    }
};