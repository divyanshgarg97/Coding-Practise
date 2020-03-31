//The game starts with a pile of n stones, and the player to move may take any positive number of stones. 
//Calculate the Grundy Numbers for this game. The last player to move wins.
//Which player wins the game?
#include<bits/stdc++.h>
using namespace std; 
vector<int> dp(11, -1 ) ; 
int calculateMEX(unordered_set<int> us){
    int mex = 0 ; 
    while( us.find(mex) != us.end())
        mex++; 
    return mex;
}
int calculateGrundy(int n ) {
    if(dp[n]!=-1)
        return dp[n];
    if( n == 0) 
        return dp[n] = 0 ; 
    if( n == 1) 
        return dp[1] = 1; 
    unordered_set<int> us; 
    for( int i = 0 ; i < n ; i ++ ) {
        us.insert(calculateGrundy(i )) ; 
    }
    return dp[n] = calculateMEX(us);
}
int main() {
    int n =10; 
    cout<< calculateGrundy(n);
    cout<< "\n";
    for( int i = 0  ;i <= n ; i++ ) 
        cout<< dp[i] <<" ";
    return 0 ; 
}