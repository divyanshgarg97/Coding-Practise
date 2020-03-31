//The game starts with a number- ‘n’ 
//the player to move divides the number- ‘n’ with 2, 3 or 6 and 
//then takes the floor.
//If the integer becomes 0, it is removed.
//The last player to move wins. Which player wins the game?

#include<bits/stdc++.h> 
using namespace std; 
int calculateMEX(unordered_set<int> us) {
    int mex = 0 ; 
    while( us.find(mex) != us.end())
        mex ++ ; 
    return mex; 
}
int calculateGrundy(int n ) {
    if( n == 0 ) 
        return 0 ; 
    unordered_set<int> us; 
    us.insert(calculateGrundy(n/2)); 
    us.insert(calculateGrundy(n/3)) ; 
    us.insert(calculateGrundy(n/6)); 
    return calculateMEX(us);
}
int main() 
{ 
    int n = 10; 
    printf("%d", calculateGrundy (n)); 
    return (0); 
} 