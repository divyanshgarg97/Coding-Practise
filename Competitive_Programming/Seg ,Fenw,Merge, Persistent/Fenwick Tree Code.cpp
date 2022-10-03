#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> // added for pbds
#include<ext/pb_ds/tree_policy.hpp> // added for pbds
#define ll                  long long // 10^19 digits
#define ull                 unsigned long long
#define MOD                 1000000007
#define IOS                 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,a,b)          for(int i=a;i<b;i++)
#define mem1(a)             memset(a,-1,sizeof(a))
#define mem0(a)             memset(a,0,sizeof(a))
//Vector Macros
#define all(v)              v.begin(),v.end()
#define unq(v)              v.erase(unique(all(v)),v.end())
#define MIN(c)              *min_element(all(c))
#define MAX(c)              *max_element(all(c))
#define SUM(c)              accumulate(all(c),0)
#define vi                  vector<int>
#define vll                 vector<ll>
#define vii                 vector<pair<int,int>>
#define pb                  push_back
#define ff                  first
#define ss                  second
#define ii                  pair<int,int>
#define endll               '\n'
#define space               " "
#define INF                 (int)1e9
#define INFLL               (ll)1e18
#define TEST                int t;cin>>t; while(t--)
#define ps(x,y)             fixed<<setprecision(y)<< x; // to set precision to number x upto y decimal digits
#define dnextline(x)        cout << #x " = " << (x) << endll
#define dsameline(x)        cout<< #x " = " << (x) << space
#define ffs(a)              __builtin_ffs(a) // find first set
#define clz(a)              __builtin_clz(a) // count leading zeroes
#define ctz(a)              __builtin_ctz(a) // count trailing zeroes
#define popc(a)             __builtin_popcount(a) // count set bits
#define popcll(a)           __builtin_popcountll(a) //count set bits for long long int
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
using namespace std;
using namespace __gnu_pbds;// for pbds
typedef tree<int,null_type,
less<int>,rb_tree_tag,
tree_order_statistics_node_update> pbds;
ll modmul(ll a,ll b,ll mod){return ((a%mod) * (b%mod)) % mod;}
ll modadd(ll a,ll b,ll mod){return((a%mod)+(b%mod)+mod)%mod;}
ll modsub(ll a,ll b,ll mod){return((a%mod) - (b%mod) + mod)%mod;}
//----------------------------------------------//
#define int long long
int t;
int n,q;
const int maxN = 100004;
vector<int> v(maxN,0);
vector<int> v1(maxN,0);
int fenw1[maxN];
int fenw2[maxN];
ll sum1(int i){ // sum for index i
    ll s=0;
    while(i>0){
        s+=fenw1[i];
        i-=(i&(-i));
    }
    return s;
}
void update1(int index, int val){
	int i = index;
	while(i <= n){
		fenw1[i] +=val;
		i+=(i&(-i));
	}
}
ll sum2(int i){ // sum for index i
    ll s=0;
    while(i>0){
        s+=fenw2[i];
        i-=(i&(-i));
    }
    return s;
}
void update2(int index, int val){
	int i = index;
	while(i <= n){
		fenw2[i]+=val;
		i+=(i&(-i));
	}
}
signed main(){
    IOS
    cin>> n;
    rep(i,0,n) {
        cin>> v[i];
        v1[i] = v[i];
    }
    mem0(fenw1);mem0(fenw2);
    sort(v1.begin(),v1.begin() + n) ;
    for(int i= 1;i<n+1;i++) // make fenwick from 1 to n as we need 0th index for doing that l--;
        update1(i,v[i-1]);
    for(int i =1;i<n+1;i++)
        update2(i,v1[i-1]);
    cin>> q;
    int l,r,type;
    int ans;
    while(q--){
        cin>> type >>  l >> r;
        l--; // as we want sum of lth element too
        if( type == 1) {
            cout<< (sum1(r)- sum1(l)) << endll;
        }
        else {
            cout<< (sum2(r) - sum2(l)) << endll;
        }
    }


}





















