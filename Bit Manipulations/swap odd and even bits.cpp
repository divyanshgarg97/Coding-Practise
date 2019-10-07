#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while( t--){
	    int n;
	    cin>>n;
	    int mask1 = 0xAAAAAAAA;
	    int mask2 = 0x55555555;
	    int even = n & mask1;
	    int odd = n & mask2;
	    even >>= 1;
	    odd <<= 1;
	    int ans = even | odd;
	    cout<<ans<<"\n";
	}
	return 0;
}