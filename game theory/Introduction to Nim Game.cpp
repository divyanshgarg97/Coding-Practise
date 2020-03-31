#include<iostream>
#include<unordered_set>
using namespace std;
int main() {
    int t; 
    cin>> t; 
    while( t--){
        int n ; 
        cin>> n; 
        int A[n] ; 
        int x; 
        for( int i =0 ; i< n;i++){ 
            cin>> A[i]; 
        }
        x = A[0];
        for( int i = 1; i < n ;i++ ) 
            x =x ^ A[i]; // result(n) = xor( g(n-1 ) , g(n-2) ,.. g(0) ) 
                         // here g(n-1) is n-1 only and same for others also after doing calculations in NIM GAME
        if( x==0)
            cout<< "Second"<< "\n";
        else 
            cout<< "First" << "\n";
    }
}