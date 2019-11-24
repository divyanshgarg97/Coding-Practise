/*
Maximum sum path in a matrix from top to bottom
Consider a n*n matrix.
Suppose each cell in the matrix has a value assigned. 
We can go from each cell in row i to a diagonally higher cell in row i+1 only [i.e from cell(i, j) to cell(i+1, j-1) and cell(i+1, j+1) only]. 
Find the path from the top row to the bottom row following the aforementioned condition such that the maximum sum is obtained.
*/
#include<bits/stdc++.h>
using namespace std; 
bool check( int i , int j,int m,int n  ) {
    if( i >= 0 && i < m  && j >=0 && j < n) 
        return true; 
    return false;
}
int main() {
    int m , n ; 
    cin>> m >> n ; 
    int a[m][n];
    for( int i = 0 ; i < m ;i++ ) for( int j = 0 ; j< n ;j++ ) cin>> a[i][j];
    int dp[m][n];
    memset( dp , INT_MIN, sizeof(dp )); // )
    for( int i = 0 ; i < n ;i++ ) 
        dp[0][i] = a[0][i];
    for( int i = 1; i< n;i++ ) {
        for( int j = 0 ; j< n;j++ ) {
            if(check(i- 1, j -1 ,m, n ) ) 
                dp[i][j] =max( dp[i][j],dp[i-1][j-1] + a[i][j]);
            if( check ( i- 1, j + 1, m ,n) ) 
                dp[i][j] = max( dp[i][j],dp[i-1][j+1] + a[i][j]);
        }
    }
    int ans = INT_MIN;
    for(int i = 0 ; i <n;i++ ) 
        ans = max( ans , dp[m-1][i]);
    cout<< ans; 
    return 0 ; 
}