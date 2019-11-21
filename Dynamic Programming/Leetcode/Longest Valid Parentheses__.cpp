class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length() ; 
        if( n == 0 ) return 0; 
        int ans = 0 ; 
        int dp[n];
        for( int i = 0 ; i < n;i++ ) {
            if( s[i] == '('){
                dp[i] = 0;
            }
            else if( s[i] ==')'){
                //two cases
                //1. only because of last i-1 is also '(' then 2 + previous
                if(i - 1> -1 && s[i-1] == '(' ){
                    dp[i] = 2 + ( (i -2)  > -1 ? dp[i-2] : 0);
                    ans = max(ans , dp[i]);
                }
                //case 2
                //2. last one is also ')' , if our current '(' can be handled earlier than consider it else current ')' is just extra ')'
                else if(s[i - 1] ==')' && i -1 > -1){
                    if( i-1 - dp[i-1 ] > -1 && s[i - 1 - dp[i-1]] =='('){
                        //can we handle the current '('
                        // if yes
                        dp[i] = 2 + (i- 1 - dp[i-1] - 1 > -1 ? dp[i - 1- dp[i-1] - 1]:0) + dp[i - 1];
                        ans = max( ans , dp[i]);
                    }
                    else{
                        dp[i] = 0; 
                    }
                }
                else
                    dp[i] = 0 ; 
                
            }
            
        }
        return ans;
    }
};