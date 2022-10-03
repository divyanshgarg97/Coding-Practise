#include<bits/stdc++.h>
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
#define D(x) cout << #x " = " << (x) << endl
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
using namespace std;
//----------------------------------------------//
int t;
const int maxN = 1e5+2;
vector<int> arr[maxN];
bool vis[maxN];
set<ii> bridge;
set<ii> cannotbridge;
int low[maxN];
int inTime[maxN];
int timer = 0 ;
void dfs(int node,int par) {
    vis[node] = true;
    inTime[node] = low[node] = timer;
    for(int child : arr[node] ) {
        if(child == par) continue;
        if( vis[child ] == 1)
            low[node]= min(low[node] , inTime[child]);
        else{
            dfs(child,node);
            low[node] = min(low[node], low[child]);
            if(low[child] > inTime[node]) { // bridge found
                if(cannotbridge.find({node,child})== cannotbridge.end()) // if not found
                    bridge.pb({node,child});
            }
        }
    }
}
int main(){
    int n,m,x,y;
    cin>>n>>m;
    ii temp;
    set<ii > checkmulti;
    for(int i=0 ;i < m ;i++ ) {
        cin>>x>>y;
        arr[x].pb(y);
        arr[y].pb(x);
        temp = {y,x};
        if(checkmulti.find(temp) != checkmulti.end()) {
            // means I have found y-x in it ,hence both x-y and y-x are present , means x-y or y-x cannot be a bridge
            cannotbridge.insert({y,x});
            cannotbridge.insert({x,y});
        }
        checkmulti.insert({x,y});// )
    }
    dfs(1,-1);
        // now I have all bridges stored in bridge
        // they all must lie in a single line for answer
    for(auto i : bridge){
        cout<< *i.first >> space << *i.second << space ;
    }
    cout<< endll;
    }
}




















