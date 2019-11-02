#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin>>n;
    lli a[n];
    for( lli i = 0 ;i< n;i++ ) 
        cin>>a[i];
    lli dp[n];
    for( lli i= 0 ;i< n;i++ ) 
        dp[i] = 1;
    lli ans =1;
    for( lli i = 1 ;i < n;i++) {
        if( a[i] -a[i-1] > -1){
            dp[i] =dp[i-1] + 1;
            if( ans < dp[i])
                ans = dp[i];
        }
    }
    cout<<ans;
    return 0;
}