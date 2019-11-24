#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
#define int long long
signed main()
 {
	//code
	int t; 
	cin>> t; 
	while( t--) {
	    int n;
	    cin>> n;
	    int a[n] ; 
	    for( int i =  0 ; i< n; i++ ) cin>> a[i];
	    int inc[n];// contains max sum of subarray for every index at its position// not all upto previous because its a subarray not subsequence 
	    inc[0] = a[0];
	    for( int i =1 ; i < n;i++  ){
	        if(a[i] > a[i-1]){
	            inc[i] = max( inc[i-1] + a[i] , a[i]);
	        }
	        else{
	            inc[i] =a[i];//max( inc[i-1],a[i]);//as subarray not subsequence
	        }
	    }
	    int dec[n];
	    dec[n-1] = a[n-1];
	    for( int i = n - 2; i >=0 ; i --) {
	        if( a[i] >a[i+1]){
	            dec[i]= max( dec[i+1]+ a[i] , a[i]);
	        }
	        else {
	            dec[i] = a[i];//max(dec[i+1] , a[i]);//as subarray not subsequence
	        }
	    }
	    int ans = INT_MIN;
	    for( int i =  0; i < n;i++ ) {
	            ans = max( ans , inc[i] + dec[i]- a[i]);//a[i] taken twice
	       
	        
	    }
	    cout<< ans << "\n";
	}
	return 0;
}