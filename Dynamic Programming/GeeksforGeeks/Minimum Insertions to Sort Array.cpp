#include<bits/stdc++.h> 
using namespace std;
int main()
 {
	//code
	int t; 
	cin>> t; 
	while( t--){
	    int n ;
	    cin>> n ;
	    int a[n];
	    for( int i = 0 ; i< n;i++ ) cin>> a[i];
	    vector<int> dp ( n , 1 ) ; 
	    int maxans = 0; 
	    for( int i = 1 ; i < n;i++ ) {
	        for(int j = 0 ;j < i ; j ++ ) {
	            if( a[i] >= a[j] ) {
	                dp[i] = max(dp[i] , dp[j] + 1);
	                maxans = max( dp[i] , maxans ) ;
	                
	            }
	        }
	    }
	    cout<<n - maxans << "\n";
	}
	return 0;
}