//my dfs
bool dfs ( vector<int> adj[], int src , vector<bool > &discovered, int parent){
    
    discovered[src]= true;
    for( auto i : adj[src]){
        if( discovered [i] == false){
            if( dfs ( adj , i , discovered , src))  
                return true;
            
        }
        else if( discovered [i] == true) {
            if( i != parent ) 
                return true; 
        }
    }
    return false;
}
bool isCyclic (vector<int> adj[], int V ){
    vector<bool > discovered ( V , false) ;
    for( int i =0 ;i < V ;i++){
        bool ans = dfs ( adj ,i , discovered,-1);  
        for( int j =0 ; j< V ;j ++)
            discovered[j] = false;
        if( ans) 
            return true;
    }
    return false;
}