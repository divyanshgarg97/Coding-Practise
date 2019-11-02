#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define take_fast {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
int n , a ,b , c,z,ans; 
int max(int a , int b , int c) {
    return max( a , max(b , c ) ) ;
}

int main() {
    cin>>n>>a >>b >> c;
    for( int x = 0 ; x <= n ;x ++) {
	    for( int y = 0 ;y <=n;y++){
		    if(((n - (a* x) - (b* y) )%c ==0) && (a* x + b*y) <=n){
		    	z = (n - a* x - b* y )/c;
		    	ans = max(ans, x + y + z) ;
		    }
		}
	}	
    cout<<ans;
return 0 ; 
}