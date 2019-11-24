//largest subarray with zero sum 
int maxLen(int a[],int n)
{
  //Your code here
    if( n== 0 ) return 0 ; 
    if( n == 1 && a[0]==0) return 1; 
    if( n == 1) return 0 ; 
    int sum = 0 ;
    int ans = 0; 
    unordered_map<int, int> ump; 
    for (int i = 0 ; i< n;i++ ) {
        sum = sum + a[i] ; 
        if( sum == 0 ) ans = i + 1; //**imp**
        if( ump.find(sum ) == ump.end()) 
            ump[sum] = i ; 
        else{
            // found a zero subarray
            ans = max( ans , i - ump[sum] );
        }
    }
    return ans; 
}
