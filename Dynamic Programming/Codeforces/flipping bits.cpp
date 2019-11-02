#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define take_fast {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
int max(int a , int b , int c) {
    return max( a , max(b , c ) ) ;
}
int main() {
    take_fast
    lli n;
    cin>>n;
    lli a[n];
    for(lli i = 0 ;i< n;i++ ) 
        cin>>a[i];
    lli v[n];
    lli sum = 0 ; 
    for ( lli i = 0 ;i< n;i++ ) {
        if( a[i] == 0){
            v[i] = 1;
        }
        else {
            v[i] = -1;
            sum++;
        }
    }
    lli dp[n+1];
    fill( dp , dp+ n + 1, 0 ) ;
    dp[0] = v[0];
    lli ans = dp[0] ; 
    for( lli i = 1 ;i< n;i++) {
        dp[i] = max(dp[i-1] + v[i] , v[i]);
        if( dp[i] > ans ) {
            ans = dp[i];
        }
    }
    cout<< (ans + sum) ;
}