#include <iostream>
using namespace std;
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int k ;
	    cin>>k;
	    int mask = 1 << (k);
	    if( n & mask )
	        cout<<"Yes\n";
	    else
	        cout<<"No\n";
	}
	return 0;
}