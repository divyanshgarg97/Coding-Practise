#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
int main()
 {
	//code
	int t; 
	cin>>t; 
	while(t--) {
	    int n; 
	    cin>> n;
	    int a[n]; 
	    for( int i = 0 ; i < n ; i++ ) cin>> a[i]; 
	    int here = a[0] ; 
	    int ans = a[0] ; 
	    for( int i =1 ; i < n;i++ ) {
	        here = here + a[i]; 
	        here = max( here, a[i]);//will handle negative values as well
	        if( here > ans) {
	            ans = here; 
	        }
	        
	    }
	    cout<< ans<< "\n";
	}
	return 0;
}