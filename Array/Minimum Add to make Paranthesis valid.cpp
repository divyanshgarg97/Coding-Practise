class Solution {
public:
    int minAddToMakeValid(string S) {
        if( S.length() == 0) 
            return 0 ; 
        int n = S.length() ; 
        string s = S;
        int ans = 0 ; 
        int o = 0 ; 
        char top;
        int i = 0 ; 
        while( i < n) {
            top = s[i];
            if( top == ')'){
                if( o > 0) {
                    o--;
                    ans--;
                }
                else
                    ans++;
            }
            else if(top == '('){
                o++;
                ans++;
            }
            i++;
        }
        return ans;
        
    }
};