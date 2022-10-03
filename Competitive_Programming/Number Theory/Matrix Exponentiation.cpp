#include<bits/stdc++.h> 
#define ll long long
#define MOD 1000000007
#define FOR(i,n) for(ll i = 0 ; i < n ;i++) 
#define FOR1(i,n) for(ll i = 1; i<= n;i++)
using namespace std; 
#define N 101
ll a[N][N];
ll I[N][N];//Identity matrix
void mul(ll A[][N],ll B[][N],ll dim){
	ll res[dim+1][dim+1];// to save results
	for(ll i = 1; i<= dim;i++){
		for(ll j = 1; j<= dim;j++){
			res[i][j] = 0 ; 
			for(ll k = 1; k<= dim;k++){
				res[i][j] = (res [i][j] +  (A[i][k] * B[k][j] % MOD)) % MOD;
			}	
		}
	}
	for(ll i=1; i<=dim;i++){for(ll j=1;j<=dim;j++){ A[i][j] = res[i][j];}}
}
void powerNaive(ll A[][N], ll dim , ll n ){//whenever we pass 2d matrix, we also need to give column
	for(ll i = 1; i <= dim; i++ ) {//initializing of identity matrix
		for(ll j = 1; j<=dim; j++){
			if( i == j ) I[i][j] = 1 ;
			else I[i][j] = 0;
		}
	}
	for(ll i = 1; i <=n ;i++ ) {
		mul(I,A,dim);//basically perform I = A * I , like res = res * x for finding x ^ n
	}
	for(ll i = 1; i<= dim;i++){
		for(ll j = 1; j<= dim;j++){
			A[i][j] = I[i][j];
		}
	}
}
void powerExponentiation(ll A[][N] ,ll dim,ll n){
	for(ll i = 1; i<= dim;i++){
		for(ll j = 1; j<= dim;j++){
			if(i == j ) I[i][j] =1;
			else I[i][j] = 0 ;
		}
	}
	while(n){
		if(n % 2){ //odd,upate result
			mul(I,A,dim); //res *= number
			n--;
		}
		else {//even,upate A
			mul(A,A,dim); // number *= number //basically compute n^2
			n/=2;
		}
	}
	for(ll i = 1; i<= dim;i++){ for(ll j = 1; i<= dim;j++){ A[i][j] = I[i][j]; }}
}
void prllMat(ll A[][N],ll dim){
	for(ll i = 1; i<= dim;i++){
		for(ll j = 1; j<= dim;j++){
			cout << A[i][j] << " ";
		}
		cout<<"\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t,dim,n;//n - power // dim - dimension of dim*dim matrix
    cin>>t;
    while(t--){
    	cin>>dim>>n;
    	for(ll i = 1; i<= dim;i++){
			for(ll j = 1; j<= dim;j++){ 
				cin>>a[i][j];
			}
		}
    	powerExponentiation(a,dim,n);
    	prllMat(a,dim);
    	//clock_t t3 = clock();
    	//prllf("Runtime = %.10lf s\n\n", (t3- t2) / (double) CLOCKS_PER_SEC);
    	//cout<< "\n";
    }
}