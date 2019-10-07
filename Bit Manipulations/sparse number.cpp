#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while( t--){
	    int n;
	    cin>> n;
	    int p = 0;
	    int i =0 ;
	    while( n ) {
	        int lastbit= n & 1 ;
	        n = n >> 1;
	        if( lastbit == 1){
	            i++ ;
	        }
	        else{
	            i = 0;
	        }
	        if( i>=2 ) {
	            cout<<"0"<<"\n";
	            p = 1;
	            break;
	            
	        }
	    }if( p == 0){
	        cout<<"1"<<"\n";
	    }
	}
	return 0;
}