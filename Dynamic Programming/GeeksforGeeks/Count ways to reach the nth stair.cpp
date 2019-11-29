#include<bits/stdc++.h> 
using namespace std;
int main()
 {
	//code
	int t;
	cin>> t; 
	while(t--){
	    int n;
	    cin>> n;
	    int dp[n+1];
	    dp[0]=1;//as ways 
	    dp[1] = 1;
	    dp[2] = 2 ; 
	    //dp[3] = 4 ;
	    for( int i = 3; i <=n;i++ ) {
	       dp[i]= dp[i-1] +dp[i-2] +dp[i-3];
	    }
	    cout<< dp[n]<<"\n";
	}
	return 0;
}