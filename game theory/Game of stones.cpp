/*
//Grundy number solution not Working
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std; 
vector<int> dp(101,-1);
int calculateMEX(unordered_set<int> us) {
    int mex = 0 ; 
    while( us.find(mex) != us.end()) {
        mex ++ ; 
    }
    return mex; 
}
int calculateGrundy(int n ) {
    if( dp[n]!= -1 ) 
        return dp[n];
    if( n == 0 ) 
        return dp[n] = 0 ; 
    if( n ==1 )
        return dp[n] = 0;
    unordered_set<int> us; 
    us.insert(calculateGrundy(n/2));
    us.insert(calculateGrundy(n/3)); 
    us.insert(calculateGrundy(n/5));
    return dp[n] = calculateMEX(us);
}
void findallgrundy(int n ) {
    for( int i = 0 ; i <n; i++ ) {
        int k = calculateGrundy(i);
    }
}
void solve( int n ) {
    int x ; 
    x = dp[n/2] ^ dp[n/3] ^ dp[n/5];
    if( x == 0 ) 
        cout<< "Second\n";
    else 
        cout<< "First\n";
}
int main() { 
    int n , t; 
    cin>> t;
    findallgrundy(101);
    while( t--) {
        cin>> n ;
        solve(n); 
    }
    for( int i = 0 ; i < 101 ; i++ ) 
        cout<< dp[i] <<" ";
}
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> dp(101, -1 ) ; 

void filldp(int n ) {
    dp[0] = 0 ; 
    dp[1] = 0 ; 
    dp[2] = 1; 
    dp[3] = 1; 
    dp[4] = 1; 
    dp[5] = 1;
    for( int i = 6 ; i <=100;i++ ) {
        if( !dp[i-2] || !dp[i-3] || !dp[i-5])
            dp[i] = 1; 
        else 
            dp[i] = 0 ; 
    }
} 
int main() {
    int t; 
    cin>> t; 
    filldp(101); 
    while( t--){
        int n; 
        cin>> n; 
        if(dp[n] == 1) 
            cout<< "First"<< "\n";
        else 
            cout<< "Second"<< "\n";
    }
}
