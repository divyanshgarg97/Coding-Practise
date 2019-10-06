bool DFS(vector<int> adj[], int v, vector<bool> &discovered,int parent){
	discovered[v] = true;
	for (int w : adj[v]){
		if (!discovered[w]){
			if (DFS(adj, w, discovered, v))
				return true;
		}
		else if (w != parent){
			return true;
		}
	}
	return false;
}
bool isCyclic ( vector<int> adj[], int V){
    vector<bool > discovered( V , false);
    //do for every source as it might happen that graph is not fully connected
    for(int i = 0 ;i< V ;i++){
        bool ans = DFS ( adj , i , discovered , -1);
        if( ans == true)
            return true;
        for( int j = 0 ; j< V;j++ )
            discovered[j] = false;
    }
    return false;
}