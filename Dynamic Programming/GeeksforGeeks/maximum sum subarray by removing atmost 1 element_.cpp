int maxSumSubarray(int a[], int n)
{
    //Your code here
    // for every index two possibilities , take or dont take and kadane's algo
    
    int f[n] ; 
    f[0] = a[0];
    int ans = a[0] ; 
    for(int i=1; i < n;i++ ) {
        f[i] = max (f[i-1], 0) + a[i];
        ans = max( ans , f[i]);
    }
    int b[n];
    b[n-1] = a[n-1];
    for( int i = n-2 ; i>=0 ; i--){
        b[i] = max( b[i+1] , 0 ) + a[i];
        ans = max( ans , b[i]);
    }
    //int ans= INT_MIN; 
    for ( int i = 1 ; i< n-1;i++ ) {
        ans = max( ans,f[i-1] + b[i+1]);
    }
    return ans  ;
}