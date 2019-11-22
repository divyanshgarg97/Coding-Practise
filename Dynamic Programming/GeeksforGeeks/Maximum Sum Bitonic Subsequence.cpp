#include <iostream>
#include<bits/stdc++.h> 
using namespace std;
int main() {
	//code
	int t; 
	cin>> t; 
	while(t--){
	    int n; 
	    cin>>n;
	    int a[n];
	    for( int i = 0 ; i < n;i++)cin>> a[i];
	    vector<int> inc(n, 0) ; 
	    vector<int> dec(n, 0) ; 
	    inc[0] = a[0];
	    for( int i = 1; i < n;i++ ) {
	        inc[i] = a[i];
	        for( int j = 0 ;j < i ;j++ ) {
	            if( a[i] + inc[j] > inc[i] && a[i] > a[j])
	                inc[i] = a[i] + inc[j];
	        }
	    }
	    dec[n-1] = a[n-1];
	    for ( int i = n -2; i>=0; i--) {
	        dec[i] =a[i];
	        for( int j = n - 1; j >i;j--){
	            if( dec[j] + a[i] > dec[i] && a[i] > a[j])
	                dec[i] = a[i] + dec[j];
	        }
	    }
	    int ans = 0 ; 
	    for( int i = 0 ; i< n;i++ ) 
	        ans = max(ans , dec[i] + inc[i] - a[i]);
	    cout<< ans<<"\n";
	}
	return 0;
}