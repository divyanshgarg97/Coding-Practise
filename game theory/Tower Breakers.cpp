#include<iostream>
using namespace std; 
int main() {
    int t; 
    cin>> t;
    while( t--){
        int n , m ; 
        cin>> n>> m ; 
        if( m == 1)  //because of line y evenly divides x which means x % y should always be 0 , if m == 1 then x ==1 and y should be less than x , hence y =0 , x % y !=0 , hence player 1 won't be able to make any move.
            cout<< 2 << "\n";
        else if(n % 2 == 0 ) // Nim game referred or editorial, both understood
            cout<< 2 << "\n"; 
        else 
            cout<< 1 << "\n";
    }
}