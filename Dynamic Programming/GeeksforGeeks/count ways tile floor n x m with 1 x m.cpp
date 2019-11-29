/*
Count the number of ways to tile the floor of size n x m using 1 x m size tiles
Given a floor of size n x m and tiles of size 1 x m. The problem is to count the number of ways to tile the given floor using 1 x m tiles. A tile can either be placed horizontally or vertically.
Both n and m are positive integers and 2 < = m.
*/
#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define big 1000000007
signed main()
 {
	//code
	int t; 
	cin>> t; 
	while( t--) {
	    int n , m ; 
	    cin>> n >> m ; 
	    vector<int> dp (n+1 , 0 ); 
	    dp[0] = 0 ;
	    dp[1] = 1; 
	    for( int i = 2 ;  i<= n;i++ ) {
	        if( m >i) 
	            dp[i] = 1;
	       else if( i ==m ) 
	           dp[i] = 2;
	       else 
	            dp[i]= (dp[i-1] + dp[i-m])%big;
	    }
	    cout<< dp[n]<<"\n";
	}
	return 0;
}