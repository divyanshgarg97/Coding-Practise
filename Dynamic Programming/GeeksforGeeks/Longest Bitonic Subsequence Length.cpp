#include<iostream>
#include<bits/stdc++.h> 

using namespace std;
int main()
 {
	//code
	int t; 
	cin>> t; 
	while(t--){
	    int n; cin>> n;
	    int a[n]; for(int i = 0 ;i < n;i++ ) cin>> a[i];// )
	    vector<int> inc(n, 1 ) ; 
	    vector<int> dec(n, 1) ; 
	    for( int i =1 ; i< n;i++ ) {
	        for( int j = 0 ; j< i;j++ ) {
	            if( a[i] > a[j] && inc[i] < inc[j] + 1)
	                inc[i] = inc[j]+1;
	        }
	    }
	    for(int i = n -2; i >=0 ;i--) {
	        for( int j = n - 1; j>i;j--){
	            if( a[i] > a[j] && dec[i] <dec[j]+1)
	                dec[i] = dec[j]+1;
	        }
	    }
	    int ans = 1; 
	    for( int i=0 ; i< n;i++ ) {
	        ans = max( ans , inc[i] + dec[i] -1); 
	    }
	    cout<< ans << "\n";
	}
	return 0;
}