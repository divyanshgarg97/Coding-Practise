#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

int main() {
	//code
	int t; 
	cin>> t; 
	while(t--) {
	    int n;
	    cin>>n;
	    int a[n];
	    for( int i= 0 ;i < n;i++ ) cin>> a[i];
	    vector<int> dp(n,0) ;
	    dp[0] = a[0];
	    int ans = a[0] ; 
	    for (int i = 1; i< n;i++ ) {
	        dp[i] = a[i];
	        for( int j = 0 ;j < i ;j++ ) {
	            if( a[i] + dp[j] > dp[i] && a[i] > a[j]){
	                dp[i] = a[i] + dp[j];
	                ans = max( ans , dp[i]);
	                
	            }
	        }
	    }
	    cout<< ans << "\n";
	    
	}
	return 0;
}