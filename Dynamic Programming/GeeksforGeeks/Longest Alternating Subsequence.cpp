#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
int main()
 {
	//code
	int t; 
	cin>> t; 
	while(t--){
	    int n ; 
	    cin>> n; 
	    int a[n];
	    for( int i = 0 ; i < n; i++ ) cin>> a[i];
	    
	    vector<int> inc(n , 1) ; /// inc[n];
	    vector<int> dec(n , 1) ; //  dec[n];
	    for( int i = 1; i < n;i++) {
	        if( a[i] > a[i-1]){
	            inc[i] = dec[i-1] + 1;
	            dec[i] = dec[i-1];
	        }
	        else if( a[i] < a[i-1]) {
	            inc[i] = inc[i-1];
	            dec[i] = inc[i-1]+1;
	        }
	        else{
	            inc[i] = inc[i-1];
	            dec[i] = dec[i-1];
	        }
	    }
	    cout<< max(inc[n-1], dec[n-1])<<"\n";
	}
	return 0;
}