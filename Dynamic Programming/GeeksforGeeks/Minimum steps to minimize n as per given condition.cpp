/*
Input:
2
10
6
Output:
3
2
*/
#include<bits/stdc++.h> 
using namespace std;
int main()
 {
	//code
	int t; 
	cin>> t; 
	while(t--){
	    int n;
	    cin>> n;
	    int dp[n+1];
	    dp[0] = 0;
	    dp[1] = 0;
	    dp[2] = 1;
	    dp[3] = 1;
	    for( int i = 4; i <=n;i++ ) {
	        dp[i] = dp[i-1]+1;
	        if( i %3 == 0 && i%2 ==0) {
	            dp[i] = min(min(dp[i/3], dp[i/2]) + 1,dp[i]) ; // );
	        }
	        else if(i % 2==0 )
	            dp[i]= min( dp[i/2] + 1, dp[i]); 
	        else if( i % 3 ==0) 
	            dp[i] = min(dp[i/3] + 1, dp[i]);
	    }
	    cout<< dp[n]<<"\n";
	}
	return 0;
}