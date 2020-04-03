class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
        //Way1:-find LCS and all other not part of LCS need to be deleted
        int n1 = word1.length() ; int n2 = word2.length(); 
        int dp[n1+1][n2+1]; 
        memset(dp,0,sizeof(dp));
        for( int i = 1 ; i <=n1; i++ ) {
            for( int j = 1 ;j <=n2; j ++ ) {
                if( word1[i-1] == word2[j-1]) 
                    dp[i][j] = 1 +dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        int lcs = dp[n1][n2]; 
        return n1 + n2 - 2 * lcs
        */
        //way2:- above LCS can be done using two 1D arrays also as for everyposition , we need only previous stored values, so store that much only and keep on updating values
        //way3:- directly make dp array to store minimum count that need to be deleted
        int n1 = word1.length() ; int n2 = word2.length(); 
        if(n1 ==0 )return n2;
        if( n2 ==0 )return n1;
        int dp[n1+1][n2+1]; 
        memset(dp,0,sizeof(dp));
        for( int i = 0 ; i <=n1; i++ ) 
            dp[i][0] = i;
        for( int i = 0 ; i <=n2; i ++)
            dp[0][i] = i;
        for( int i = 1 ; i <=n1; i++ ) {
            for( int j = 1 ;j <=n2; j ++ ) {
                if( word1[i-1] == word2[j-1]) 
                    dp[i][j] =dp[i-1][j-1];
                else 
                    dp[i][j] =1+min(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[n1][n2];
        /*
        //wrong as sequence order should also be same,
        int count[26] = {0}; 
        for( int i =0 ; i < word1.length() ;i++ ) 
            count[word1[i] -'a']++;
        for( int i = 0 ; i < word2.length() ; i ++ ) 
            count[word2[i] - 'a']--;
        int ans = 0 ; 
        for( int i= 0 ; i < 26;i ++ ) 
            ans = ans + abs(count[i]);
        return ans;
        */
    }
};