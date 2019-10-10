oid fillindegree( vector<int> &indegree,int V ,vector<int> adj[]){
    for( int i = 0 ;i< V; i++ ){
        for( auto j : adj[i]){
            indegree[j] ++ ;
        }
    }
}
int * topoSort( int V , vector<int>adj []){
    vector<int> indegree;
    fillindegree( indegree , V, adj);
    vector<int> s;
    vector<int> l;
    for( int i = 0 ; i <V ;i++){
        if( indegree[i]==0){
            s.push_back(i);
        }
    }
    while( !s.empty()){
        int i = s.back() ;
        s.pop_back();
        l.push_back( i ) ;
        for( auto j : adj[i]){
            indegree[j]= indegree[j]-1;
            if( indegree[j] == 0)
                s.push_back(j);
        }
    }
    static int answer[50];
    for( int i = 0 ;i < l.size();i++)
        answer[i] = l[i];
    return answer;
}