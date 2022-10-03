#include<bits/stdc++.h>
#define ii pair<int,int>
#define pb push_back
#define endll "\n"
using namespace std;

// Problem variables
const int maxN = 1e5+2;
vector<ii> adj[maxN];
int U[maxN],V[maxN];

// FOR HLD
int subtree_size[maxN];// store subtree size of every node(including itself(obviously))
int chain[maxN]; // I am in which chain
int chainHead[maxN]; // who is my chain head
int position[maxN]; //
int chainId = 0;// to fill Chain values in chain and chainHead, we need a variable
int pos = 0; // to fill values in segtree ,we need one variable

// FOR SEG TREE
int n;
int arr[maxN]; // to make ST tree(as we are using only one segment tree) , so we need to keep track of indices such that all nodes that belong to same chain are together, that is why we use this arr
int tree[4*maxN +1]; // to make segment tree

// FOR LCA
int MAX;// column size of parent array as in binary lifting (log2(maxN))
int parent[maxN][100+1];// lca with binary lifting storage
int level[maxN];// what is my depth

//----- SEGMENT TREE STUFF ----
void build(int treein,int low,int high){ // segment tree build code ,simple
    if(low == high) {
        tree[treein] = arr[low];
    }
    else{
        int mid = (low + high)>> 1;
        build(2*treein,low,mid);
        build(2*treein+1,mid+1,high);
        tree[treein]= max(tree[2*treein],tree[2*treein+1]);
    }
}
//segment tree update
void update(int treein,int low,int high,int idx,int val){
    if(low==high)
        tree[treein] = val;
    else{
        int mid = (low+high)>>1;
        if(idx<=mid)
            update(2*treein,low,mid,idx,val);
        else
            update(2*treein+1,mid+1,high,idx,val);
        tree[treein] = max(tree[2*treein],tree[2*treein+1]);
    }
}
//segment tree query
int query(int treein,int low,int high,int l,int r){
    if(l<=low && high<=r) // overlap
        return tree[treein];
    if(low>r || high<l) // outside range
        return 0;
    int mid = (low+high)>>1;
    return max(query(2*treein,low,mid,l,r),query(2*treein+1,mid+1,high,l,r));
}
int query(int l,int r){
    if(l>r)
        return 0;
    return query(1,0,n-1,l,r);
}
void update(int idx,int val){
    update(1,0,n-1,idx,val);
}
// ---- SEGMENT TREE STUFF ENDS ----//

void dfs(int v,int par,int l) { // done // to do binarylifing things and storing subtree sizes
    parent[v][0]= par;
    for(int i =1;i<=MAX;i++ ) {
        int temp = parent[v][i-1];
        if(temp!=0){
            parent[v][i]= parent[temp][i-1];
        }
    }
    subtree_size[v]+=1;
    level[v] = l;
    for(ii p : adj[v]){
        if(p.first!=par){
            dfs(p.first,v,l+1);
            subtree_size[v]+=subtree_size[p.first];
        }
    }
}
int queryUp(int from ,int to){ // to move up form NODE from(A or B) to NODE to(LCA)
    int curr = from;
    int ans = 0;
    while(chain[curr]!=chain[to]){ // will run until chain to curr and lca becomes the same
        int currentChain = chain[curr]; // my chain
        int currentChainHead = chainHead[currentChain]; // mychainshead
        ans = max(ans,query(position[currentChainHead],position[curr])); // get max from curr to its currentChainHead
        curr = parent[currentChainHead][0]; // move curr to new chain
    }
    // now we are in the same chain as LCA
    ans = max(ans,query(position[to] + 1, position[curr]));
    return ans;
}
void HLD(int v,int par){
    int heavyChild = -1;// who is my heavyChild
    int heavySize = 0 ; // size of my heavyChild
    int heavyEdgeWeight = -1; //to add value in my seg tree as this is the main value on which Seg tree will be made
    chain[v] = chainId;//
    for(ii p : adj[v]){ // will find which of my children is the heaviest among all the children
        if(p.first != par) {
            if(subtree_size[p.first] > heavySize) {
                heavySize = subtree_size[p.first];
                heavyChild = p.first;
                heavyEdgeWeight= p.second;
            }
        }
    }
    if(heavyChild!= -1) { // i.e. I have found a heavy child for this node
        arr[pos] = heavyEdgeWeight; // add value in segment tree
        HLD(heavyChild,v); // call for my heavy child
    }
    for(ii p : adj[v]){ // to do HLD for my light child
        if(p.first != par && p.first != heavyChild){ // second condition as heavy child was already updated
            chainId++ ; // as now chain will be made new , as previos chain was used for heavy child as we cannot go both sides in making of same chain
            chainHead[chainId] = p.first; // new chain is made, hence for this chain, update its first node too
            arr[pos] = p.second;// store in segment tree
            HLD(p.first,v);// call HLD for my nodes
        }
    }
}

int lca(int u,int v) { // find lca between any two nodes
    if(level[u] > level[v]){ // make node v deeper
        swap(u,v);
    }
    int diff = level[v] - level[u];
    for(int i = MAX; i >=0;i--) {
        if((diff& (1<<i)) !=0)
            v = parent[v][i];
    }
    if(u == v) return u;
    for(int i = MAX;i>=0;i--) {
        if( parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
void init(int n){
    for(int i = 1; i <=n;i++ ) {
        adj[i].clear();
        U[i] = 0;
        V[i] = 0;
        chainHead[i] = -1;
        position[i]=0;
        subtree_size[i]=0;
        arr[i] = 0;
        level[i] =0;
        for(int j =0 ;j <= MAX;j++ )
            parent[i][j] = 0;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        chainId = 0;
        pos = 0;
        cin>> n;
        MAX = (int)(log(n)/log(2));// or MAX = (int) log2(n)
        //init(n);
        int u,v,c;// for input
        for(int i= 1; i<n;i++){
            cin>>u>>v>>c;
            adj[u].pb({v,c});
            adj[v].pb({u,c});
            U[i] = u;
            V[i] = v;
        }
        int sz = (int)pow(2,ceil(log(n)/log(2)) + 1);
        for(int i= 0 ;i < sz ; i++ )
            tree[i] = 0;
        dfs(1,0,0);
        chainHead[0] = 1;
        HLD(1,0);
        build(1,0,n-1);
        while(true){
            string s;
            cin>>s;
            if(s == "DONE")
                break;
            if(s == "QUERY"){
                int u,v,LCA;
                cin>>u>>v;
                LCA=lca(u,v);
                int max1 = 0;
                max1 = max(max1,queryUp(u,LCA));
                max1 = max(max1,queryUp(v,LCA));
                cout<< max1<<endll;
            }
            else{
                int idx,cost;
                cin>>idx>>cost;
                int u = U[idx];
                int v = V[idx];
                if(level[u] > level[v]){
                    update(position[u],cost);
                }
                else{
                    update(position[v],cost);
                }
            }
        }
    }
}
