class Solution {
public:
    string longestPalindrome(string s) {
        //dp solution,expand around centre and best is Manachar's algo
        int n = s.length();
        if( n == 0 ) return s; 
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for( int i = 0 ; i < n ;i++ ) 
            dp[i][i] = 1; 
        for(int l = 2; l <= n ; l ++ ) {
            for( int i = 0 ; i < n-l + 1; i ++ ) {
                int j = i + l - 1; 
                if(s[i]==s[j] && l == 2 ) 
                    dp[i][j]=1;
                else if( s[i] == s[j]){
                    if( dp[i+1][j-1]==1 ) 
                        dp[i][j] = 1; 
                    else 
                        dp[i][j] =0;
                }
                else 
                    dp[i][j] =0;
            }
        }
        // to print the anwer, max(j-i) if dp[i][j] = 1;
        int ansi = 0;
        int ansj = 0;
        int maxval = 1;
        //for( int i =  0; i  <n ;i++ ) {
        //    for( int j = 0 ;j < n ;j ++ ) 
        //        cout<< dp[i][j]<<" ";
        //    cout<< "\n";
        //}
        for( int i = 0 ; i < n; i++){
            for( int j = i ;j < n ;j ++ ) {
                if( dp[i][j] ==1){
                    if( j - i + 1 > maxval ) {
                        maxval = j - i + 1; 
                        ansi = i ; 
                        ansj = j ; 
                    } 
                }
            }
        }
        string temp; 
        for( int i = ansi ; i <= ansj; i++ ) 
            temp = temp + s[i];
        return temp;
        
    }
};