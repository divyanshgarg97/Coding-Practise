#include<bits/stdc++.h> 
#define int long long 
#define big 1000000007
using namespace std;
signed main()
 {
	//code
	int t; 
	cin>> t; 
	while( t--){
	    int n ;
	    cin>> n;
	    vector<int> last0(n , -1 ) ; 
	    last0[0] = 1;
	    //last0 denotes number of ways to get a binary string without consecutive strings such that last element is 0 including ith index
	    vector<int> last1(n,-1);
	    last1[0] = 1; 
	    for(int i = 1 ; i < n;i++ ) {
	        last0[i] =(last1[i-1] + last0[i-1]) % big ;
	        last1[i] = last0[i-1]; 
	    }
	    cout<< (last0[n-1] + last1[n-1]) % big<< "\n";
	}
	return 0;
}