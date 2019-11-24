#include<bits/stdc++.h> 
using namespace std;
int main()
 {
	//code
	int t; 
	cin>>t; 
	while(t--){
	    int n; cin>> n;
	    int a[2][n] ;
	    for ( int i = 0 ; i< 2;i++ ) 
	        for( int j = 0 ;j < n;j++ ) 
	            cin>> a[i][j];
	    int ans = a[0][0];
	    int dp[2][n];
	    memset( dp , 0 , sizeof(dp)) ; 
	    dp[0][0] =a[0][0];
	    dp[1][0] =max( dp[0][0], a[1][0]);
	    dp[0][1] = max( dp[1][0],a[0][1]);
	    dp[1][1]=  max(dp[0][1] ,  a[1][1]);
	    if( n >2 ) { 
	            for( int j = 2; j < n;j++ ) {
	                for( int i= 0 ; i< 2; i++ ) {
	                    dp[i][j] = max(dp[i][j-2] , dp[(i + 1) % 2][j-2]) + a[i][j];
	                    dp[i][j] = max( dp[i][j] ,dp[i][j-1]);
	                }
	            }
	    }
	    cout<< max( dp[0][n-1], dp[1][n-1]) << "\n";
	}
	return 0;
}