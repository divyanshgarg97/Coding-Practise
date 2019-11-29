#include<bits/stdc++.h> 
using namespace std;
#define int long long
signed main()
 {
	//code
	int t; 
	cin>>t; 
	while( t--) {
	    int n; 
	    cin>> n; 
	    int a[n];
	    for( int i = 0 ; i < n;i++ ) cin>> a[i];
	    vector<int> dp( n ,INT_MAX) ; 
	    dp[0] = 0 ;
	    for( int i = 1; i < n;i++ ) {
	        for( int j = 0 ;j < i ; j++ ) {
	            if( a[j] - i+j >=0 && dp[j]!=INT_MAX)// + j (IMP), check can jump and can reachable
	                dp[i] = min( dp[i] , dp[j] + 1);
	        }
	    }
	    cout<<(dp[n-1]!=INT_MAX ? dp[n-1] : -1) <<"\n";
	    
    }
	return 0;
}