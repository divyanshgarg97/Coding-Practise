#include<bits/stdc++.h> 
using namespace std;
int main()
 {
	//code
	int t; 
	cin>> t; 
	while(t--) {
	    string s; 
	    cin>> s; 
	    int n = s.length() ;
	    // kadane's algo
	    int curr ; 
	    int here = (s[0]=='0')? 1 :0 ; 
	    int ans_till = max( 0 , here);
	    for( int i = 1; i < n;i++ ){
	        if( s[i] =='0')
	            curr = 1; 
	        else 
	            curr = -1 ; 
	        here = max (0 , here + curr) ; 
	        ans_till = max ( ans_till , here) ;
	    }
	    if( ans_till == 0) {
	        cout<<"-1"<< "\n";
	        break;
	    }
	    cout<<  ans_till<<"\n"; 
	}
	return 0;
}