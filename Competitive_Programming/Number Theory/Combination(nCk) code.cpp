#include<bits/stdc++.h> 
#define lli long long
using namespace std;
lli C(int n , int k ) {
	lli ans =1;
	if( k > n -k) {
		k = n - k ;
	}
	for(lli i = 1; i<=k;i++){
		ans *= (n-i+1);
		ans /=i;
	}
	return ans;
}
int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		cout<< C(n,k) << "\n";
	}
}
