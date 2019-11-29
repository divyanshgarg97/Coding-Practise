#include<bits/stdc++.h> 
using namespace std;
#define int long long
signed main()
 {
	//code
	int t; 
	cin>> t; 
	while( t--){
	    //logic 1 
	    /*
	    int n;
	    cin>>n;
	    int a[n];
	    for( int i = 0 ; i < n;i++ ) cin>> a[i];
	    vector<int> dp ( n , 1 ) ; // dp[n];
	    int ans = 0 ; 
	    //memset( dp , 1 , sizeof(dp) );
	    for( int i = 1; i < n;i++ ) {
	        for( int j =0 ; j < i ;j++ ) {
	            if( a[i] > a[j]){
	                dp[i] += dp[j];
	            }
	        }
	        ans+= dp[i] ; // 1 value less as i started from 1
	    }
	    cout<< ans+1 << "\n";
	    */
	    //logic 2 :as values are from 0 to 9 only 
	    int n; 
	    cin>> n; 
	    int a[n] ; 
	    for( int i = 0 ; i < n; i++ ) cin>>a[i] ; 
	    vector<int> count ( 10 , 0) ;
	    for( int i =0 ; i < n;i++ ) {
	        for( int j = 0 ;j < a[i] ;j ++ ) {
	                count[a[i]] +=count[j]; 
	        }
	        count[a[i]]++;
	    }
	    int ans = 0 ; 
	    for( int i = 0 ; i < 10 ;i ++ ) 
	        ans = ans + count[i];
	    cout<< ans << "\n";
	}
	return 0;
}