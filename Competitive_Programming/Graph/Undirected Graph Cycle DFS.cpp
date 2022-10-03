// cycle increases the number of ways to reach from one node to another
// for example with trees , we have only path to reach from one node to another
// basically we needs to find back edges in graph
// eg
// calling structure 1--> 2 --> 3 --> 4--> 2 (backedge found, hence cycle found)
// basically if any node connects to its ancestor which is not its parent then cycle found

//            1
//           /
//          2
//         / \
//        3 -4
//            \
//             5

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
bool dfs(int node,int par) {
    vis[node] =1;
    for(int child : arr[node]){
        if(vis[child] == 1) {
            if(child != par)
                return true;
        }
        else {
            if(dfs(child,node) == true)
                return true;
        }
    }
    return false;
}
int main(){
    IOS
    cin>>t;
    while(t--){
    }
}




















