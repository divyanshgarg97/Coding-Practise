#include<bits/stdc++.h> 
#define int long long int 
using namespace std;
void swap( int & a , int &b ) {
    int temp = a; 
    a =b; 
    b = temp ; 
}
signed main()
 {
	int t; 
	cin>> t; 
	while( t--) {
	    int n;
	    cin>>n ;
	    int a[n] ; 
	    for( int i  = 0 ; i  < n;i++ ) cin>>a[i] ; 
	    /*Approach 1 :-when we swap imin and imax if we encounter a -ve value
	    int ans = a[0];
	    int imin = a[0];
	    int imax = a[0];
	    for( int i = 1 ; i< n;i++ ) {
	        if( a[i] < 0 ) {
	            swap ( imin , imax) ; 
	        }
	        imin = min( a[i] ,imin * a[i]);
	        imax = max(a[i] , imax * a[i]);
	        ans = max( ans , imax) ; 
	    }
	    cout<< ans <<"\n";
	    */
	    //Approach 2 :- general case
	    //although both are kind of same only
	    int imin = a[0];
	    int imax = a[0];
	    int ans = a[0];
	    int prev_min = imin; 
	    for( int i = 1; i < n;i++ ) {
	        imin = min(imin * a[i] ,min( imax * a[i] , a[i]));
	        imax = max(imax * a[i] , max( prev_min * a[i] , a[i]));
	        ans = max( ans , imax) ;
	        prev_min = imin;
	    }
	    cout<< ans << "\n";
	}
	return 0;
}