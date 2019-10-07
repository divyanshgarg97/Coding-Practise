#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while( t --){
	    int n;
	    cin>>n;
	    int k ;
	    cin>>k;
	    //left 
	    int n1 = n;
	    int temp = 0 ;
	    temp = (n << k ) | (n >> ( 16- k ));
	    cout<<temp<<"\n";
	    temp = (n1 >> k ) | (n1 << (16 -k ));
	    cout<<temp<<"\n";
	}
	return 0;
}