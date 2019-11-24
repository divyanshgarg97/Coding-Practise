#include<bits/stdc++.h> 
using namespace std;
int main()
 {
	//code
	int t; 
	cin>> t; 
	while(t--) {
	    int n;
	    cin>> n;
	    int a[n] ; 
	    for( int i = 0 ; i< n;i++ ) cin>> a[i] ; 
	    int  k ; 
	    cin>> k ; 
	    sort( a , a + n ) ; 
	    vector<int> dp ( n , 0 ) ; 
	    dp[0] = 0;
	    if( a[1] - a[0] < k ) 
	        dp[1] = a[0] +a[1];
	    else 
	        dp[1] = 0; 
	    int ans = 0 ; 
	    for( int i = 2; i < n;i++ ) {
	        if( a[i]- a[i-1] < k ) {
                    dp[i] = max(dp[i-1], a[i] + a[i-1] + dp[i-2]);
                    ans = max(ans , dp[i]);
	        }
	        else {
	            dp[i] = dp[i-1];// as it is like subsequence not subarray
	            ans = max( ans , dp[i]);
	        }
	        
	    }
	    cout<< dp[n-1]<<"\n";
	    
	    
	}
	return 0;
}