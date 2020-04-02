class Solution {
public:
    int max(int a , int b){
        return (a>b)?a:b;
    
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1= text1.length() ;
        int n2= text2.length() ;
        int dp[n1+1][n2+1];
        memset( dp , 0 , sizeof(dp)); 
        for( int i= 1 ;i<= n1;i++){
            for( int j= 1; j <= n2;j++){
                if( text1[i-1] ==text2[j-1]){//i-1 and j -1 //take care
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        
        }
        for( int i = 0 ;i<=n1;i++){
            for( int j = 0 ;j<=n2;j++){
                //cout<<dp[i][j];
            }
            cout<<"\n";
        }
        return dp[n1][n2];
    }
};