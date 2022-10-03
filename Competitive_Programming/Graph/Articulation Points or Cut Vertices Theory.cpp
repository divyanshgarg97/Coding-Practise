// Articulation point or cut vertex is a vertex which when removed makes graph disconnected or more precisely it increases the number of connected components.
// when we remove a vertex than we will also remove all the incident edges on it(if directed then all incident (as outgoing toh hogi bhi ni) and 
// if undirected then all edges connected to it will be removed)

//Relation between Articulation points and bridges
    // AN END POINT OF A BRIDGE IS A ARTICULATION POINT
    // Why?So when we have a bridge A-----B , then if I remove A also then A----B will be gone and connected component increase, same goes for B as well
    // BUT not all of them are Articulation points , some are and some are not
    // Why?
//          A ----- B
//         / \          In this graph , only A is articulation point and B is not a articulation point.
//        /   \
//       /     \
//      D ----- C
    // Final :- Whatever nodes around Bridge which have degree > 1 is a Articulation point
    // But is it that only Bridges can lead to Cut Vertex(articulation points)?
    // NO
    // Articulation point can exist even if we don't have a bridge
    // Eg:- Refer code n code video lecture


    CONCLUSIONS::--
    1. End Point of bridge may or may not be articulation point depending upon its degree(if degree >1 then Yes else NO)
    2. It is not necessary for a articulation point to be an end-point of a bridge
    3. Finding bridges algorithms cannot be used to find Articulation point

    ALGORITHM:-
    For root we will not compare whether it is articulation point or not,as it will always turn out to be articulation point according to our algo





    // So basically when we can run Bridge algorithm,and whenever we get a bridge,we can store both its nodes in a set



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
const int maxN = 1e5+1;
vi arr[maxN];
bool vis[maxN];
vi inTime,low;
int timer = 0;
void dfs(int node,int par = -1) {
    vis[node] = true;
    low[node] = inTime[node] = timer++;
    int children = 0; // this is we are doing to correct for root node
    if(int child : arr[node]){
        if(child == par) continue;
        if(vis[child]) {
            //back edge found
            // minimize low time
            low[node]= min(low[node],inTime[child]);
        }
        else{
            dfs(child,node);
            low[node] = min(low[node],low[child]);
            if(low[child] >= inTime[node] && par!= -1) { // means child kisi bhi aise vertex tak nahi pahuch sakta jo mere se pehle exist hua ho , hence I am CUT-Vertex
                // then node is a cutoff vertex
                cout<< "CUT OFF VERTEX FOUND Which is " << node <<endl;
            }
            children++; // basically a different subtree found for our node
        }
    }
    if(p == -1 && children > 1) // if p = -1 means if this node was a root as we are doing this children for root only
                                // root of every connected component will check this
                                // children > 1 means at least 2 branches exist for this roots DFS tree
                                // eg(the below is not graph, it is a DFS TREE)  , now A can be a Articulation  point because children is 2 which is B and C ,And if I remove A , Connection between B and C is lost and connected components will increase
                                            A
                                          /  \
                                         B     C
                                        / \   / \
                                       F   G  D   E
        cout<< "CUT OFF VERTEX FOUND which is "<< node << endl;
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

























