//sieve ,sieve(n),prime factors
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007 // 10^9 + 7
using namespace std;
bool p[MOD];
void sieve(){ // complete range sieve
	for(int i = 2; i < MOD ; i++ ) // iniitializing all are prime
		p[i] = true;
	for( int i = 2; i < MOD; i++ ){
		if( p[i]){
			for(int j = 2 * i ; j < MOD; j+=i)
				p[j]=false;
		}
	}
	p[0] = false;//by definition of prime
	p[1] = false;//by definition of prime
}
void sieven(int n){ //sieve upto n (n included)
	for(int i = 2; i <= n ;i++ ) {
		p[i] = true;
	}
	for(int i = 2; i<= n;i++){
		if( p[i]){
			for( int j = 2 * i ; j <= n;j+=i)
				p[j] = false;
		}
	}
}
vector<int> pf; // to store all prime numbers in a vector
void store() {
	for(int i = 2; i < MOD; i++ ) {
		if(p[i])
			pf.push_back(i);
	}
}
vector<int> ans; // clear it every time you use it
void factorize1(int n){
	int i = 0 ;
	ll f = pf[0];
	while( f*f <= n){
		if(n % f ==0){
			ans.push_back(f);
			while(n%f==0)
				n/=f;
		}
		i++;
		f = pf[i];
	}
	if(n!=1) // if n was already a prime number,then it won't be check as above loop upto sqrt(n)
		ans.push_back(n);
}
void factorize2(int n ) { // using the least prime divisor concept
    vector<int> lp(n+1,0);
    lp[1] = 1;
    for(int i =2;i<=n;i+=2)
        lp[i] = 2;
    for(ll i = 3; i<=n; i++) {
        if(lp[i] == 0){
            lp[i] = i;// marking self marked
            for(ll j = 2*i;j<=n;j+=i){ // marking all due to me
                if(lp[j] ==0)
                    lp[j] = i;
            }
        }
    }
    // above will store for every number from 1 to n what is its least prime divisor in O(nLognLogn)(sieve complexity);
    // now as I only need to factorize n , do this
    set<int> factors;
    while(n > 1) { // O(logN) as maximum case mein everytime gets divided by 2
        int val = lp[n];
        factors.insert(lp[n]);
        n = n / lp[n];
    }
    // set factors will contain all the prime factors of number n
    // rather than using set , we can use map too to store the count of each factor also
}
int main(){
    sieven(40);
    store();
    int x ;cin>>x;
    factorize(x);
    for(int i= 0 ; i < ans.size();i++)
    	cout<< ans[i] << " ";
    cout<< "\n";
    ans.clear();
}
