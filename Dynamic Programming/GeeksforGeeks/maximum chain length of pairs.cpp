bool mycomp( struct val a , struct val b ) {
    return a.first < b.first; 
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    sort( p, p + n , mycomp); 
    vector<int> dp ( n , 1 ) ; 
    int ans = 1 ; 
    for ( int i = 1 ;i  < n;i++ ) {
        for( int j= 0 ;j < i ;j ++ ) {
            if( p[j].second  < p[i].first){
                dp[i] = max( dp[i] , dp[j]+1);
                ans = max( ans , dp[i]);
            }
        }
    }
    return ans; 
}