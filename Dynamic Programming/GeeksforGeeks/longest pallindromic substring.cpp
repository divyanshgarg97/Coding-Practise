#include<bits/stdc++.h> 
#define int long long
using namespace std;
//longest palindromic substring

pair<int , int>  DP ( string s ) {
    int n = s.length() ; 
    vector<vector<bool> > dp ( n , vector<bool> ( n ,false ) ) ;
    int start = 0 ; 
    int length = 1; 
    for( int i =0 ;i < n-1;i++ ) {
        dp[i][i] = true;
        if( s[i]== s[i+1]){
            dp[i][i+1] = true;
            if( 2 > length) {
                length = 2 ; 
                start = i ; 
            }
        }
    }
    dp[n-1][n-1]=true; 
    for( int l = 3; l <= n;l ++ ) {
        for( int i = 0 ; i < n - l + 1; i ++ ) {
            int j = i + l - 1; 
            if( s[i] == s[j]){
                if( dp[i+1][j-1] == true){
                    dp[i][j] = true; 
                    if( l > length) {
                        length = l ; 
                        start = i; 
                    }
                }
            }
        }
    }
    return make_pair(start, length) ;
}


signed main()
 {
	//code
	int t; 
	cin>> t; 
	while( t--){
	    string s ;
	    cin>> s; 
	    pair<int, int>  ans = DP (s) ; 
	    string a;
	    for( int i = ans.first ; i < ans.first  + ans.second ; i ++ )
	        a = a + s[i];
	    cout<< a << "\n";
	}
	return 0;
}