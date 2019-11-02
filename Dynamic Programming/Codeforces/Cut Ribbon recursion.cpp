#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define take_fast {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
int n , a ,b , c; 
int max(int a , int b , int c) {
    return max( a , max(b , c ) ) ;
}
int dp[4001];
int go(int i ) {
    if( i ==0) return 0;
    if( i < 0 || (i > 0 && i <a && i < b && i < c ))
        return INT_MIN;
    if(dp[i]==0)
        dp[i] = max( go(i - a ) , go(i - b) , go(i-c) ) + 1; 
    return dp[i];
}
int main() {
    cin>>n>>a >>b >> c; 
    int ans = go( n ) ;
    cout<<ans;
} 