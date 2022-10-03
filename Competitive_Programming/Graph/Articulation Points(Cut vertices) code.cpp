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
const int maxN = 1e5+1;
vi arr[maxN];
bool vis[maxN];
vi inTime,low;
int timer = 0;
set<int> articulationPoints; // use set or some bool array for storage as roots can be counted twice at line 43 and 50
void dfs(int node,int par = -1) {
    vis[node] = true;
    low[node] = inTime[node] = timer++;
    int children = 0;
    if(int child : arr[node]){
        if(child == par) continue;
        if(vis[child]) {
            // back edge
            low[node]= min(low[node],inTime[child]); // child can also be ancestor
        }
        else{
            dfs(child,node); // forward edge
            low[node] = min(low[node],low[child]);
            if(low[child] >= inTime[node] && par!= -1) { // in bridge we have > only ( we don't check for equality there)
                articulationPoints.insert(node);
                cout<< "CUT OFF VERTEX FOUND IS " << node <<endl;
            }
            children++; // in else
        }
    }
    if(p == -1 && children > 1)
        cout<< "CUT OFF VERTEX FOUND IS "<< node << endl, articulationPoints.insert(node);
}


int main(){
    IOS
    int n,m,x,y;
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        arr[x].pb(y),arr[y].pb(x);
    }
    int par = -1;
    for(int i = 1; i<=n;i++){ // as we might have more than one connected components
        if(!vis[i])
            dfs(i,par);
    }
}
























