#include<bits/stdc++.h> 
using namespace std;
int main()
 {
	//code
	int t; 
	cin>> t; 
	while(t--) {
	    int n;
	    cin>>n;
	    //approach 1 : Coin change type O(n2)
	    /*int a[3] = {3, 5, 10 } ; 
	    int dp[3][n+1];
	    for( int i = 0 ; i <=n;i++ ) {
	        if( i % a[0] == 0 )
	            dp[0][i]=1;
	        else 
	            dp[0][i] = 0 ; 
	    }
	    for( int i = 0 ; i<3; i++ ) 
	        dp[i][0] = 1; 
	    for( int i = 1 ; i < 3; i++ ) {
	        for( int j = 0 ; j <=n;j++ ) {
	            if(j < a[i] ) {
	                dp[i][j] = dp[i-1][j];
	            }
	            else{
	                dp[i][j]  = dp[i][j-a[i]] + dp[i-1][j];
	            }
	        }
	    }
	    cout<< dp[2][n]<<"\n";*/
	    //optimization in above approach O(n) 
	    int dp[n+1];
	    memset( dp , 0 , sizeof(dp) );
	    dp[0] = 1; 
	    for( int i = 3 ; i<=n ; i++ ) {
	        dp[i] = dp[i] + dp[i-3]; 
	    }
	    for( int i = 5; i <=n;i++ ) 
	        dp[i] = dp[i] + dp[i-5]; 
	    for( int i = 10 ; i <=n;i++ )   
	        dp[i] = dp[i] + dp[i-10]; 
	   cout<< dp[n]<<"\n";
	}
	return 0;
}