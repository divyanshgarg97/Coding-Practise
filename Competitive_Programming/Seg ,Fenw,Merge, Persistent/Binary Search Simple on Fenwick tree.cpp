//   codechef.com/problems/NPLFLC

#include <bits/stdc++.h>
#define loop(i,n)    for( int i=0; i<n; i++ )
#define loop1(i,a,n) for( int i=a; i<n; i++ )
#define vloop(i,a)   for( vector<int>::iterator i=a.begin(); i!=a.end(); i++ )
#define dloop(i,a)   for( deque<int>::iterator i=a.begin(); i!=a.end(); i++ )
#define PI 3.14159265
#define bc __builtin_popcountl
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb push_back
#define pf push_front
#define rf pop_front
#define rb pop_back
#define mp make_pair
#define fs first
#define sc second
#define fi ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
const ll M=1e9+7;
const int INF=1e9;
 
inline ll pwr(ll base,ll n,ll m){ll ans=1;while(n>0){if(n%2==1)ans=(ans*base)%m;base=(base*base)%m;n/=2;}return ans;}

const int sz = (int)1e5 + 2;

ll a[sz], bit[sz] = {0}, z, y, total = 0;
int n, q, x, type;

void update( int index, ll v ) {
    
    while( index <= n ) {
        bit[index] += v;
        index += (index & -index);
    }
    
}


ll get( int index ) {
    
    ll res = 0;
    
    while( index > 0 ) {
        res += bit[index];
        index -= (index & -index);
    }
    
    return res;
}

bool found( ll val ) {
    
    int lo = 1, hi = n;
    int md = ( lo + hi )>>1;
    
    ll v = get(md);
    
    while( lo < hi ) {
        md = ( lo + hi )>>1; 
        v = get(md);
        if( v == val )
            return true;
        if( v < val )
            lo = md+1;
        else
            hi = md - 1;
        
    }
    
    if( get(lo) == val || get(hi) == val )
        return true;
    return false;
    
}

int main() {
    
    fi;
    cin>>n;
    
    loop1(i,1,n+1) {
        cin>>a[i];
        total += a[i];
        update(i,a[i]);
    }
    
    cin>>q;
     
    while( q-- ) {
        
        cin>>type;
        
        if( type == 1 ) {
            cin>>x>>y;
            update(x,y-a[x]);
            total += y-a[x];
            a[x] = y;
        }
        else {
            cin>>z;
            string res = "NO";
            if ( total - z == 0 || found( total - z ) )
                res = "YES";
            cout<<res<<"\n";
        }
       
    } 
    
    return 0;
}