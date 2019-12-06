#include<bits/stdc++.h> 
using namespace std;
bool checkpal( string s , int i , int j ) {
    for(int k = i , l = j ; k<=j ; k++ , l -- ) {
        if( s[k] !=s[l]) 
            return false;
    }
    return true;
}
int DP1 ( string s ) {
    int n = s.length() ; 
    vector<vector<int> > dp ( n , vector<int> ( n , INT_MAX) ) ; 
    for( int i = 0 ; i< n;i++ ) {
        dp[i][i] = 0;
    }
    for( int i = 0 ; i < n -1 ; i++ ) {
        if( s[i]==s[i+1])
            dp[i][i+1] = 0;
        else
            dp[i][i+1] = 1;
    }
    //2 ways , length and from back side
    /*Working
    for( int l = 3; l <= n ;l ++ ){
        for( int i = 0 ; i< n - l + 1; i ++ ) {
            int j = i + l -1 ; 
            if( checkpal(s , i , j ) ) 
                dp[i][j] = dp[i+1][j-1];
            else {
                for( int k = i ;k <j ;k++ ) {
                    dp[i][j] = min( dp[i][j] , dp[i][k] + dp[k+1][j] + 1);
                }
            }
        }
    }
    */
    for( int i = n -1 ; i>= 0 ; i -- ){
        for( int j = i + 2; j < n ; j ++ ) { // j should begin from i + 2 as for length  1 , 2 , it is already computed
            if( checkpal(s , i , j ) ) 
                dp[i][j] = dp[i+1][j-1];
            else {
                for( int k = i ;k <j ;k++ ) {
                    dp[i][j] = min( dp[i][j] , dp[i][k] + dp[k+1][j] + 1);
                }
            }
        }
    }
    return dp[0][n-1];
}
int DP2(string s ) {
    int n = s.length() ; 
    vector<vector<bool> > pal( n , vector<bool> ( n , false) ) ; 
    vector<vector<int> > dp( n , vector<int> ( n ,0) ); 
    for( int i = 0 ; i < n-1 ;i++ ) {
        pal[i][i] = true; 
        if( s[i] == s[i+1]){
            pal[i][i+1] = true; 
        }
        else {
            dp[i][i+1] = 1; 
            pal[i][i+1] = false; 
        }
    }
    pal[n-1][n-1] = true; 
    for( int l = 3; l <= n ;l ++ ){
        for( int i = 0 ; i< n - l + 1; i ++ ) {
            int j = i + l -1 ; 
            if( s[i] == s[j]){
                if(pal[i+1][j-1]){ 
                    dp[i][j] = 0;
                    pal[i][j] = true; 
                }
            }
            else 
                pal[i][j] = false; 
            if( pal[i][j]){
                dp[i][j] = 0 ;
            }
            else {
                dp[i][j] = INT_MAX; 
                for( int k = i ;k <j ;k++ ) {
                    dp[i][j] = min( dp[i][j], dp[i][k] + dp[k+1][j] + 1 );
                }
            }
        }
    }
    return dp[0][n-1];
}
int main()
 {
	//code
	int t; 
	cin>> t; 
	while( t--){
	    string s; 
	    cin>> s; 
	    //int ans = recur( s ,0 , s.length() -1 ) ;
	    //int ans = DP1 ( s ) ; 
	    int ans = DP2(s ) ; 
	    cout<< ans << "\n";
	}
	return 0;
}