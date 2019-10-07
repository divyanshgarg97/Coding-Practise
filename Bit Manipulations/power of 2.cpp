#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    if( n == 0 ) {
	        cout<<"NO\n";
	        continue;
	    }
	    //cin>>n;
	    if( n & (n-1))
	        cout<<"NO\n";//<<"\n";
	    else
	        cout<<"YES\n";
	}
	return 0;
}