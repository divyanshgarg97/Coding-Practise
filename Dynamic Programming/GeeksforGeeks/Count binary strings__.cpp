#include<bits/stdc++.h> 
#define big 1000000007
#define int long long 
using namespace std;
signed main()
 {
	//code
	int t; 
	cin>> t ;
	while( t--){
	    int n, k ; 
	    cin>> n >> k ; 
	    int dp[n+1][k+1][2];//[0] means last element added was 0 ,  [1] means last element added was 1 
	    //dp[i][k][0] represents number of ways to make binary string of length i with k consecutive 1's and ended last digit was 0
	    memset( dp , 0 , sizeof(dp)) ; 
	    dp[1][0][0] = 1;//if k > 0 then 0 only as cannot get more consecutive for n =1  
	    dp[1][0][1] =1;//if k > 0 then 0 only as cannot get more consecutive for n =1
	    for( int i = 2 ; i<=n;i++ ) {
	        for( int j = 0 ;j <=k ;j++ ) {
	            dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1])% big;
	            dp[i][j][1] = (dp[i-1][j][0] + ((j - 1) > -1? dp[i-1][j-1][1]: 0)) % big ;
	        }
	    }
	    cout<< (dp[n][k][0] + dp[n][k][1])%big<<"\n";
	    
	}
	return 0;
}