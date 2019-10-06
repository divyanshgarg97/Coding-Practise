struct node {
    int src , parent;
};
bool bfs( vector<int> adj[], int src, vector<bool> discovered) {
    queue<node> q;
    discovered[src] = true;
    q.push({src, -1});
    while( !q.empty()){
        node v = q.front() ;
        q.pop();
        for( auto i : adj[v.src]){
            if(discovered[i] ==false ){
                discovered[i] = true;
                q.push({i , v.src});
            }
            else{
                if( i != v.parent){
                    return true;
                }
            }
        }
    }
    return false;
}
bool isCyclic(vector<int> adj[], int V)
{
    vector<bool > discovered (V , false) ;
    for( int i = 0 ;i< V ;i++ ){
        bool ans = bfs ( adj , i , discovered);
        if(ans == true){
            return true;
        }
        for( int j = 0 ;j < V ;j++ )
            discovered [j] = false;
    }
    return false;
}