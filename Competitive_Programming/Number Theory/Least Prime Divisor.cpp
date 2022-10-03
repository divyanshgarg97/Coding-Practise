#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> // added for pbds
#include<ext/pb_ds/tree_policy.hpp> // added for pbds
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define forz(i,n) for(ll i = 0 ; i < n ;i++)
#define foro(i,n) for(ll i = 1; i<= n;i++)
#define fort(i,s,e) for(ll i = s ; i<e; i++)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<ii>
#define vll vector<pair<ll,ll> >
#define endll '\n'
#define space " "
#define INF 1000000000
#define ps(x,y) fixed<<setprecision(y)<< x; // to set precision to number x upto y decimal digits
#define D(x) cout << #x " = " << (x) << endl
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
using namespace std;
using namespace __gnu_pbds;// for pbds
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
ll modmul(ll a,ll b,ll mod){return ((a%mod) * (b%mod)) % mod;}
ll modadd(ll a,ll b,ll mod){return((a%mod)+(b%mod)+mod)%mod;}
ll modsub(ll a,ll b,ll mod){return((a%mod) - (b%mod) + mod)%mod;}
//----------------------------------------------//
int t;
void leastPrime(int n){
    vector<int> lp(n+1,0);
    lp[1] = 1;
    for(int i =2;i<=n;i+=2)
        lp[i] = 2;
    for(ll i = 3; i<=n; i++) {
        if(lp[i] == 0){
            lp[i] = i;// marking self
            for(ll j = 2*i;j<=n;j+=i){ // marking all due to me
                if(lp[j] ==0)
                    lp[j] = i;
            }
        }
    }
}
void bestLeastPrime(int n){
    vector<int> lp(n+1,0);
    lp[1] = 1;
    for(int i =2;i<=n;i+=2)
        lp[i] = 2;
    for(ll i = 3; i<=n; i++) {
        if(lp[i] == 0){
            lp[i] = i;// marking self
            for(ll j = i*i;j<=n;j+=2*i){ // marking all due to me
                if(lp[j] ==0)
                    lp[j] = i;
            }
        }
    }
}
int main(){
    IOS
    cin>>t;
    while(t--){
    }
}




















