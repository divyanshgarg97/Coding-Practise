//sieve ,sieve(n),segmentedSieve(a,b)
#include<bits/stdc++.h> 
#define ll long long 
#define MOD 1000000007 // 10^9 + 7
using namespace std; 
bool p[MOD];
void sieve(){ // complete range sieve
	for(int i = 2; i < MOD ; i++ ) // iniitializing all are prime
		p[i] = true;
	for( int i = 3; i < MOD; i+=2 ){
		if( p[i]){
			for(int j = 2 * i ; j < MOD; j+=i)
				p[j]=false;
		}
	}
	p[0] = false;//by definition of prime
	p[1] = false;//by definition of prime
}
void sieve(int n){ //sieve upto n (n included)
	for(int i = 2; i <= n ;i++ ) {
		p[i] = true;
	}
	for(ll i = 2; i<= n;i++){
		if( p[i]){
			for( ll j = 2 * i ; j <= n;j+=i)
				p[j] = false;
		}
	}
}
void bestsieve(int n){
	for(int i = 2; i <=n; i+=2)
		p[i] = false;
	for(ll i = 3; i<=n; i++ ) {
		if(p[i]) {
			for(ll j = i*i;j<=n;j+=2*i){
				p[j] = false;
		}
	}
}
void segmentedSieve(ll a, ll b ) {
	sieve();
	bool pp[b-a+1];
	memset(pp,true,sizeof(pp));
	for(ll i = 2; i*i <=b;i++ ) {
		if(p[i]){
			for( ll j = a; j <= b ; j++ ) {
				if( i== j ) //overlapping
					continue;
				if(j%i ==0) 
					pp[j-a] =false;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif

}