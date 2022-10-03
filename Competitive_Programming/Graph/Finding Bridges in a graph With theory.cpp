// With Theory Explanation from codencode

//Bridge in a graph is a edge which when removed makes graph disconnected or Increase number of connected components in graph after disconnection

// DFS TREE:- When we make a DFS call , some of the edges are traversed and some of them are not traversed,becacause destination node was already visited
//            If we mark all edges that were traversed as BLACK and which were not as GREY then
//            BLACK edges are called Forward Edge and GREY are called Back edges
//            We will always get a tree when considering only Black Edges which is called as DFS Tree
//            Each Back Edge , when we add it to our DFS tree , then they will form cycle.
//            A Back edge connects a node to its ancestor(which is not its direct parent).
//        NOTE:- BACK edge can never be  a BRIDGE(obviously) as usse hatane se bhi connected component toh increase honge hi ni because already connected hai ,back edge will add only cycle to it and also there already exist path from that ancestor to node before back edge


// FINDING BRIDGES IN A GRAPH
// Timer begins from 0
// Store 'In time' of every Node maintain  ancestor children relationship
// and 'Low' stores what is the lowest time at which any of my ancestor(not direct parent) that can be reached directly from that node
// Basically using this 'Low' array , for every edge (both the nodes around this edge) is having storing the time which is the time at which one of its ancestor which is not directly was visited.
// So to check for Bridge,
// if I am at EDGE a-----b , and to check a----b is a Bridge or not then
// low[b] > inTime[a] , means b is connected to some ancestor of which was visited even before existence of a
// low[b] < inTime[a] , means b is connected than it is connected in forward edge(not in back side),hence, we can remove it and if not connected than also we can remove it



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
        if(vis[child]==1){ // back edge found as visited and also not its direct parent
            //edge node-child is a back edge
            low[node] = min(low[node],inTime[child]);
            // take minimum,why? consider graph    1 , we start from 1->2->3->4 (found back edge),
            //                                     |  //update value for 4 then revert back 4->3->2(at 2,4 is also visited and not parent , so backedge found which is true but now it won't help to do low[node] = low[child] as child 4 will have more time
            //                                     |
            //                                     2
            //                                    / \
            //                                   3 - 4
        }
        else{
            // edge node-child is a forward edge
            dfs(child,node);
            if(low[child] > inTime[node]){
                //means , this edge is Bridge
                cout << node << "---" << child << space << "is a BRIDGE  " << endl;
            }
            //update node's lowtime now
            // as child was connected to node , so if child can reach to some ancestor than node can also reach to it using child
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

























