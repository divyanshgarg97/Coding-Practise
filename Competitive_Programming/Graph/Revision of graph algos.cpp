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
const int maxN =1e5+3;
// Articulation points 1st or cut vertices, the more complicated one compared to bridges
vector<int> arr[maxN];
bool vis[maxN];
set<int> ap;
int inTime[maxN];
int low[maxN];
int timer;
void dfs(int node , int par) {
    vis[node] = 1;
    inTime[node] = low[node] = timer;
    timer ++;
    int children = 0 ;
    for(int child : arr[node]) {
        if(child == par) continue;
        if(vis[child] == 1) {
                // back edge
            low[node] = min(low[node] , inTime[child]);
        }
        else{
            dfs(child,node) ;
            low[node] = min(low[node] , low[child]);
            if(low[child] >= inTime[node] && par !=-1){
                ap.insert(node);
            }
            children ++;
        }
    }
    if( par == - 1 && children > 1) {
        ap.insert(node);
    }
}
// articulaiton points twice
vector<int> arr[maxN] ;
bool vis[ maxN];
int inTime[maxN];
int low[maxN] ;
int timer ;
set<int> ap;
void dfs(int node, int par = -1 ) {
    vis[node] = 1;
    inTime[node] = low[node] = timer;
    timer ++;
    int children = 0 ;
    for(int child : arr[node] ) {
        if(child == par) continue;
        if(vis[child] == 1) {
            // back edge
            low[node] = min(low[node] ,inTime[child]);
        }
        else{
            children ++;
            dfs(child,node);
            low[node] = min(low[node] , low[child]);
            if(low[child] >= inTime[node] && par !=-1) {
                ap.insert(node);
            }
        }
    }
    if( par == -1 && children >1)
        ap.insert(node);
}

// bridges first
const int maxN = 1e5 + 1;
vector<int> arr[maxN] ;
bool vis[maxN];
int timer = 0 ;
int low[maxN];
int inTime[maxN];
set<ii> bridges;
void dfs(int node, int par = - 1) {
    vis[node] = true;
    inTime[node] = low[node] = timer++;
    for(int child : arr[node]){
        if(child == par) continue;
        if(vis[child] == 1) {
            low[node] = min(low[node] , inTime[child]);

        }
        else{
            dfs(child,node);
            low[node] = min(low[node] , low[child]);
            if( low[child] > inTime[node] ) {
                bridges.insert({node,child});
            }
        }
    }
}
// bridges twice
const int maxN = 1e5 + 2;
vector<int> arr[maxN];
bool vis[maxN];
int inTime[maxN];
int low[maxN];
int timer = 0 ;
set<ii> bridges;
void dfs(int node, int par=-1) {
    vis[node] = 1;
    inTime[node] = low[node] = timer++;
    for(int child : arr[node] ) {
        if( child == par) continue;
        if( vis[child])
            low[node] = min(low[node],inTime[child]);
        else{
            dfs(child,par) ;
            low[node] = min(low[node] , low[child]);
            if(low[child] > inTime[node])
                bridges.insert({node,child});
        }
    }
}
// topological sort
// we first take a node with 0 indegree , remove all its connections and move next node with zero indegree
const int maxN = 1e5 + 2;
vector<int> arr[maxN];
int in[maxN];
vector<int> ans;
void kahn(int n) { // size is passed
    queue<int> q;
    for(int i = 1; i<=n;i++) {
        if(in[i] == 0)
            q.push(i);
    }
    int temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        ans.pb(temp);
        for(int child : arr[ans]){
            in[child]--;
            if(in[child] == 0 )
                q.push(child);
        }
    }

}
// topological sort twice
const int maxN = 1e5 + 2;
vector<int> arr[maxN];
int in[maxN];
vi ans;
void kahn(int n){
    queue<int> q;
    for(int i= 1 ;i <=n;i++ ) {
        if( in[i] == 0)
            q.push(i);
    }
    int temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        ans.push(temp);
        for(int child : arr[temp]){
            in[child]--;
            if(in[child] == 0)
                q.push(child);
        }
    }
    cout<< "TOPOLOGICAL SORTING" << endl;
    for(auto i : ans) {
        cout<< *i<< space;
    }
}
// djiktras algorithm once
const int maxN = 1e5 + 2;
vector<ii> arr[maxN]; // (destination,weight)
void main(){
    int n,m,x,y,w;
    cin>>n>>m;
    for(int i= 0 ; i< m;i++ ) {
        cin>> x >> y >> w;
        arr[x].pb({y,w});
        arr[y].pb({x,w});
    }
    priority_queue<ii,vii,greater<ii> > pq;
    vector<int> dist(n+1,INF);
    int src;
    cin>>src;
    pq.push({0,src});
    while(!pq.empty()){
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        for(ii node : arr[curr]){
            if( node.second + curr_ d < dist[node.first]){
                dist[node.first] = curr_d + node.second;
                pq.push({dist[node.first], node.first});
            }
        }
    }
    for(int i = 1; i <= n;i++ )
        cout<< dist[i] << endll;
}

// djiktras algorithm twice
const int maxN = 1e5+3;
vector<ii> arr[maxN];
int main() {
    int n,m,x,y,w;
    cin>> n>> m;
    for(int i = 0; i< m ;i++ ) {
        cin>> x >> y;
        arr[x].pb({y,w});
        arr[y].pb({x,w});
    }
    vector<int> dist(n+1,INF);
    priority_queue<ii,vii,greater<ii> > pq;
    int src;
    cin>> src;
    dist[src]= 0 ;
    pq.push({0,src});
    while(!pq.empty()){
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();
        for(ii node: arr[curr]){
            if( node.second + curr_d  < dist[node.first]){
                dist[node.first] = node.second + curr_d;
                pq.push({dist[node.first], node.first});

            }
        }
    }
    for(int i = 1;i <= n;i++ )
        cout<< dist[i] << endll;
}

// kruskal code MST once
const int maxN = 1e5 + 2;
struct edge{
    int a,b,w;
};
edge arr[maxN]; // will store edges, basically maxN here is number of edges
int par[maxN]; // will store or of size total nubmer
bool comp(edge a,edge b) {
    if( a.w < b.w) return true;
    return false;
}
int Find(int a) {
    if(par[a] == -1)
        return a;
    return par[a] = Find(par[a]);
}
void Merge(int a,int b) {
    par[a] = b;
}
int main(){
    IOS
    int sum = 0 ;
    int n,m,x,y,w;
    cin>>n>>m;
    for(int i =1 ;i <= n;i++ ) par[i] = - 1;
    for(int i= 0 ; i< m ;i++ ) cin>> arr[i].a >> arr[i].b >> arr[i].w;
    sort(arr,arr+m,comp);
    int para = -1;
    int parb = -1;
    for(int i= 0;i < m ;i++) {
        para = Find(arr[i].a);
        parb = Find(arr[i].b);
        if(para!=parb) {
            sum += arr[i].w;
            Merge(para,parb);
        }
    }
    cout<< sum << endll;
}

// kruskal code twice
struct edge{
    int a,b,w;
};
const int maxN1 = 1e5 + 3;
const int maxN2 = 1e2 + 3;
edge arr[maxN1] ; // maxN1 = number of edges
int par[maxN2]; // maxN2 = total number of nodes
bool comp(edge a, edge b) {
    if(a.w < b.w) return true;
    return false;
}
void Merge(int a,int b) {
    par[a] = b;
}
int Find(int a){
    if(par[a] == -1) return a;
    return par[a] = Find(par[a]);// path compresion
}
void main(){
    int sum= 0;
    int n,m,x,y,w;
    cin>>n>>m;
    for(int i = 0 ;i < m;i++)
        cin>> arr[i].a>> arr[i].b >> arr[i].w;
    for(int i = 0 ; i<= n;i++ ) par[i] = -1;
    sort(arr, arr + m ,comp) ;
    int para;
    int parb;
    for(int i = 0 ;i < m ;i++ ) {
        para = Find(arr[i].a);
        parb = Find(arr[i].b);
        if(para != parb) {
            sum += arr[i].w;
            Merge(para,parb);
        }
    }
    cout<<sum<<endll;
}
// Binary lifting once
const int maxN = 1001;
int level[maxN];
vector<int> arr[maxN];
int lca[maxN][10+1]; // columns will be choosen according to maxN value
void dfs(int node,int lvl,int par) {
    level[node]= lvl;
    lca[node][0] = par;
    for(int child : arr[node] ) {
        if(child!= par)
            dfs(child,lvl+1,node);
    }
}
void init(){
    memset(lca,-1,sizeof(lca));
    dfs(1,0,-1);
    for(int i = 1; i < 11; i++ ) {
        for(int j = 1;j<=n ;j++ ) {
            int par = lca[j][i-1];
            if( par!=-1)
                lca[j][i] = lca[par][i-1];
        }
    }
}
int getlca(int a,int b){
    // make node b deeper than a
    if(level[a] > level[b]) swap(a,b);
    int diff = level[b] - level[a];
    while(diff >0) {
        int i = log2(diff);
        b = lca[b][i];
        d -=1<<i;
    }
    if( a== b) return a;
    for(int i = 10;i>=0;i--){
        if(lca[a][i]!=-1 && (lca[a][i] != lca[b][i]))
            b = lca[b][i] ,a = lca[a][i];
    }
    return lca[a][0];

}
int getDist(int a,int b) {
    int lca= getLca(a,b) ;
    return level[a] + level[b] - 2*level[lca];

}


// binary lifting twice
const int maxN = 1e5+2;
vector<int> arr[maxN];
int lca[maxN][100]; // column will get decided using log2(maxN)
int level[maxN];
void dfs(int node, int lvl,int par){
    level[node] = lvl;
    lca[node][0] = par;
    for(int child : arr[node]) {
        if( child == par) continue;
        dfs(child,lvl+1,node);
    }
}
void init(){
    dfs(1,0,-1);
    memset(lca,-1,sizeof(lca));
    for(int i = 1 ; i < 100 ; i++ ){
        for(int j = 1; j <= n;j++ ) {
            int par = lca[j][i-1];
            if( par !=-1) {
                lca[j][i] = lca[par][i-1];
            }
        }
    }
}
void getLca(int a,int b) {
    if( level[b] < level[a] ) swap (a,b) ;
    int diff = level[b] - level[a];
    while( diff > 0) {
        int jump = log2(diff);
        b = lca[b][jump] ;
        diff -= (1<<jump);
    }
    if( a== b) return a;
    for(int i = 100 ;i >=0; i--) {
        if( lca[a][i] != -1 && (lca[a][i] != lca[b][i]))
            b = lca[b][i],a = lca[a][i];
    }
    return lca[a][0];
}
// binary lifting thrice
const int maxN = 10000;
vector<int> arr[maxN];
int lca[maxN][100];// column should be calculated by log2(maxN)
// lca should be instantiated with -1 from the main method
int level[maxN];
void dfs(int node, int lvl, int par) {
    level[node] = lvl;
    lca[node][0] = par;
    for(int child : arr[node] ) {
        if( child == par) continue;
        dfs(child,lvl+1,node);
    }
}
void init(){
    dfs(1,0,-1);
    for(int i = 1; i <100;i++ ) {
        for(int j = 1; j <= n;j ++ ) {
            int par = lca[j][i-1];
            if( par !=-1)
                lca[j][i] = lca[par][i-1];
        }
    }
}
int getLca(int a,int b) {
    init();
    if( level[b] < level[a] ) swap(a,b) ;
    int diff = level[b] - level[a];
    int jump;
    while(diff > 0) {
        jump = log2(diff);
        b = lca[b][jump] ;
        diff -= (1<< jump);
    }
    if( a== b) return a;
    for(int i = maxN ; i>=0 ;i++ ) {
        if(lca[a][i] != -1 && (lca[a][i] != lca[b][i])) {
            b = lca[b][i] , a = lca[a][i];
        }
    }
    return lca[a][0];
}
int getDist(int a,int b ){
    int LCA = getLca(a,b);
    return level[a] + level[b] - level[LCA];

}

// bipartite or not once
const int maxN = 1e5+ 2;
vector<int> arr[maxN];
bool col[maxN];
bool vis[maxN];
void dfs(int node, int c){
    vis[node] = 1;
    col[node] = c;
    for(int child : arr[node]) {
        if(vis[child]) {
            if( col[child] == col[node] )
                return false;
        }
        else{
            if( dfs(child,c^1) == false)
                return false;
        }
    }
    return true;
}
// bipartite or not twice
const int maxN = 1e4 + 2;
vector<int> arr[maxN];
bool vis[maxN];
bool col[maxN];
void dfs(int node, bool c) {
    vis[node] = 1;
    col[node] = c;
    for(int child : arr[node]) {
        if(vis[child]) {
            if(col[child] == col[node])
                return false;
        }
        else{
            if(dfs(child,c^1) == false)
                return false;
        }
    }
    return true;
}
// cycle in undirected grpah once
const int maxN = 1e5 + 3;
vector<int> arr[maxN];
bool vis[maxN];
bool dfs(int node, int par) {
    vis[node]=1;
    for(int child:arr[node]){
        if( vis[child] == 1) {
            if(child!=par)
                return true;
        }
        else{
            if(dfs(child,node)==true)
                return true;
        }
    }
    return false;
}

// cycle in undireceted graph twice
const int maxN = 1e5 + 5;
vector<int> arr[maxN];
bool dfs(int node, int par) {
    vis[node] = 1;
    for(int child : arr[node] ) {
        if( vis[child] == 1) {
            if( child != par)
                return true;
        }
        else {
            if( dfs(child,node) == 1)
                return true;
        }
    }
    return false;
}



// cycle in directed graph



// floydwarshall once
// floydwarshall twice

// bellman ford once
// bellman ford twice

// hamiltonian cycle  and order once
// hamiltonian cycle and order twice
