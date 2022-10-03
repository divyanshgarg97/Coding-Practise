// to find the distance between 2 nodes in a tree using LCA in Log(n);
//dist = level[a] + level[b] - 2* level[LCA] // simple , can easily observe this
#include<bits/stdc++.h> 
using namespace std;
#define MAX 1001 // let 1000 nodes in the tree
vector<int> ar[1001]; // adjacency list> ;
int level[1001];
const int maxN= 10;
int lca[1001][maxN+1];

void dfs(int node,int lvl ,int par){
    level[node] = lvl;
    lca[node][0] = par;
    for(int child : ar[node]){
        if( child!=par){
            dfs(child ,lvl + 1, node);
        }
    }
}
void init(int n ) {
    dfs(1,0,-1);
    for(int i= 1; i <= maxN;i++){
        for(int j = 1; j <= n ;j ++ ) {
            if(lca[j][i-1] !=-1){
                int par = lca[j][i-1];
                lca[j][i] = lca[par][i-1];
            }
        }
    }
}
int getLCA(int a ,int b ) {
    if(level[b] < level[a] ) swap(a,b); // as we want b to be deeper
    
    int d = level[b] - level[a];
    while(d > 0) {
        int i = log2(d);
        b = lca[b][i];
        d -= 1 << i;
    }
    if (a ==b ) return a;
    for(int i = maxN; i >=0  ; i--) {
        if(lca[a][i] !=-1  && ( lca[a][i]!=lca[b][i])){
            a = lca[a][i],b=lca[b][i];
        }
    }
    return lca[a][0];
}
int getDist(int a ,int b){
    int lca = getLCA(a ,b);
    return level[a] + level[b] - 2 * level[lca];
}
int main(){
    int n,a,b,q; 
    cin>> n ; 
    for(int i = 1; i <= n;i++ ) {
        for(int j = 0 ; j <= maxN; j++ ) {
            lca[i][j] =-1;
        }
    }
    for( int i = 1; i < n ; i++ ) { //for n nodes there will be n - 1 edges as we are working on trees
        cin>> a >> b , ar[a].push_back(b),ar[b].push_back(a);        
    }
    init(n); // initialize lca array
    cin>>q;
    while(q--){
        cin>> a >> b; 
        cout<< getDist(a,b) << "\n";
    }
    
}