#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

int main() {
	//code
	int t; 
	cin>>t ; 
	while(t--) {
	    int n; 
	    cin>>n; 
	    int a[n];
	    int ans = 1;
	    for( int i = 0 ; i< n ;i++) cin>> a[i];
	    //O(n^2 ) solution
	    /*vector<int> dp(n , 1) ; 
	    for( int i = 1; i< n;i++ ) {
	        for( int j = 0 ;j < i ;j++ ) {
	            if( abs(a[i] - a[j])==1 && dp[j] + 1 > dp[i] ){
	                dp[i] = dp[j] + 1;
	                ans = max(ans , dp[i]);
	            }
	        }
	    }
	    cout<< ans<<"\n";
	    */
	    
	    //O(n) solution
	    vector<int> dp (1001 ,0) ;
	    for( int i = 0 ; i < n;i++ ) {
	        dp[a[i]] = max( dp[a[i]-1] , dp[a[i] +1])+1;
	        ans = max(ans , dp[a[i]]);
	        
	    }
	    cout<< ans<< "\n";
	}
	return 0;
}