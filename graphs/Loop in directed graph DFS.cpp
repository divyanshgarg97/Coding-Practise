bool dfs (vector<int> adj[] ,int v,int parent , vector<bool >&discovered,vector<bool > recurstack){//make sure recursion stack to not to be of reference type{
    discovered[v] = true;
    recurstack[v] = true;
    for( auto i : adj[v]){
        if( !discovered[i]){
            if(dfs ( adj , i , v , discovered, recurstack))
                return true;
        }
        else if( discovered[i] == true){
            if( i == parent){ // parent to node cycle is found
                return true;
            }
            else {
                // can be false or true as now we have directed graph not undirected graph
                //that is why we need some recursion stack kind of thing here
                if( recurstack[i] == true)
                    return true;
                
            }
        }
    }
    return false;
}
bool isCyclic(int V, vector<int> adj[]){
    int parent = -1; 
    vector<bool > recurstack(V, false);
    vector<bool > discovered(V , false);
    for(int i = 0 ;i< V ;i++){
        bool ans = dfs( adj , i , -1 , discovered,recurstack);
        if( ans) 
            return true;
        for( int j = 0 ;j< V ;j++){ 
            discovered[j] = false;
            recurstack[j] = false;
        }
    }
    return false;
}