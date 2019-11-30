/*int recur( string s , string t, int i , int j ) {
    if( j < 0 || i < 0 ) return 0 ; 
    if( j == 0 ) {
        return 1 ; 
    }
    if( i == 0)
        return 0 ; 
    if( s[i-1] == t[j-1]){
        return recur( s , t , i - 1, j ) + recur( s ,t , i-1, j -1 )  ; 
    }
    if( s[i-1] !=t[j-1]){
        return recur( s , t , i -1 , j ) ; 
    }
    
}*/
int subsequenceCount(string S, string T)
{
  //Your code here
  /*cannot send S.length() -1 and T.length() -1 as in function , written j == 0 return 1 and i === 0 return 0
  int ans = recur( S, T , S.length() , T.length() ) ; 
  return ans; 
  */
  string s = S; int n = S.length() ; string t = T; int m = T.length() ; 
  vector<vector<int> > dp(n+1 , vector<int> ( m +1, 0 ) ) ;
  
  
  for( int i = 0 ; i <= m ;i++ ){
      dp[0][i] = 0 ;
  } 
  for( int j= 0 ; j<= n ;j++ ) {
      dp[j][0] = 1; 
  }
  for( int i = 1; i <= n ;i ++ ) {
      for( int j = 1; j <=m ;j ++ ) {
          if( s[i-1] == t[j-1]){
              dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
          }
          else { 
              dp[i][j] = dp[i-1][j];
          }
      }
  }
  return dp[n][m]; 
}
 
