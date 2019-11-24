/*
Given a N X N  matrix Matrix[N][N] of positive integers.  There are only three possible moves from a cell Matrix[r][c].

1. Matrix[r+1][c]

2. Matrix[r+1][c-1]

3. Matrix[r+1][c+1]

Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.
*/
#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
bool check( int i , int j , int n ) {
    if( i >-1 && i < n&& j >-1 && j < n)
        return true; 
    return false;
}
int main()
 {
	//code
	int t; 
	cin>> t; 
	while( t--) {
	    int n; 
	    cin>> n; 
	    int a[n][n];
	    for(int i = 0 ; i < n;i++ ) for( int j = 0 ;j < n;j++ ) cin>> a[i][j];
	    int dp[n][n];
	    memset( dp ,INT_MIN, sizeof( dp )) ; 
	    int ans = INT_MIN; 
	    for( int i = 0 ; i < n;i++ ) dp[0][i] = a[0][i];
	    for( int i = 1; i < n;i++) {
	       for( int j = 0 ; j< n ;j++ ) {
	           if( check( i - 1,j,n ) ) 
	                    dp[i][j] = max( dp[i][j] , dp[i-1][j] + a[i][j]);
	           if( check( i - 1, j -1,n ))
	                    dp[i][j] = max( dp[i][j] , dp[i-1][j-1] + a[i][j]);
	           if( check( i - 1, j + 1,n )) 
	                dp[i][j] = max( dp[i][j] , dp[i-1][j+1]+ a[i][j]);
	            ans = max( ans , dp[i][j]);
	       } 
	    }
	    cout<<ans<< "\n";
	    
	    
	}
	return 0;
}