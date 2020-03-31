#include<bits/stdc++.h> 
using namespace std; 
#define maxval 100002
vector<int> prime(maxval,1); // initiliazing all are prime
void primesieve() {
    for( int i =2; i < maxval ; i++ ) {
        if( prime[i]){
            for( int j = i * 2; j < maxval ; j= j+ i ){
                prime[j] = 0 ; // 0 means not prime
            }
        }
    }
    prime[0] = 0; 
    prime[1] = 0;
}
int main() {
    int t;
    cin>> t;
    primesieve(); 
    while( t--){
        int n; 
        cin>> n;
        int check = 0 ; 
        for( int i = 1 ;i <=n;i++ ){
            if( prime[i])
                check++; 
        }
        if( check % 2 ==0) 
            cout<< "Bob"<<"\n";
        else 
            cout<< "Alice"<<"\n";
    }
}
