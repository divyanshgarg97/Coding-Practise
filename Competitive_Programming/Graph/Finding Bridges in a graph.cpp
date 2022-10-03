#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define for0(i,n) for(ll i = 0 ; i < n ;i++)
#define for1(i,n) for(ll i = 1; i<= n;i++)
#define for2(i,s,e) for(ll i = s ; i<e; i++)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<ii>
#define vll vector<pair<ll,ll> >
#define endl '\n'
#define space " "
#define INF 1000000000
#define D(x) cout << #x " = " << (x) << endl
int dx[] ={-1,0,1,0};int dy[] ={0,1,0,-1};
using namespace std;
//----------------------------------------------//
int t;
const int maxN = 101;
vector<int> arr[maxN];
int inTime[maxN],low[maxN],vis[maxN];
int timer;
void dfs(int node,int par){
    vis[node] = 1;
    inTime[node] = low[node] = timer;
    timer++;
    for(int child:arr[node]){
        if(child == par) continue;
        if(vis[child]==1) // back edge found
            low[node] = min(low[node],inTime[child]);
        else{
            dfs(child,node);
            // if low[child] == inTime[node] means child and node are directly connected means there is a path other than child--- node edge using which the low gets updated for child as inTime[node] , thus not an BRIDGE
            if(low[child] > inTime[node]) // bridge found
                cout << node << "---" << child << space << "is a BRIDGE  " << endl;
            low[node]=min(low[node],low[child]);
        }
    }
}
int main(){
    IOS
    int n,m,x,y;
    cin>>n>>m;
    while(m--)
        cin>>x>>y,arr[x].pb(y),arr[y].pb(x);

    dfs(1,-1);
}
