//The game starts with a pile of n stones, and the player to move may take any positive number of stones upto 3 only. 
//The last player to move wins. Which player wins the game? 
//This game is 1 pile version of Nim
#include<bits/stdc++.h>
using namespace std;
int calculateMEX(unordered_set<int> us) {
    int mex = 0 ; 
    while( us.find(mex) != us.end()) 
        mex ++ ; 
    return mex; 
}
int calculateGrundy(int n ) {
    if(n == 0) 
        return 0; 
    if( n == 1) 
        return 1; 
    if( n == 2)
        return 2; 
    unordered_set<int> us;
    for( int i = 1; i <= 3; i ++){
        us.insert(calculateGrundy(n - i ) ) ; 
    }
    return calculateMEX(us);
}

int main() {
    int n = 10 ; 
    cout<< calculateGrundy(n) ; 
    //for( int i= 0  ;i <= n ;i++ ) 
    //    cout<< dp[i]<<" ";
}