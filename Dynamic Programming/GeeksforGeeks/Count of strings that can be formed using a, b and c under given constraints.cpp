/*
Given a length n, count the number of strings of length n that can be made using ‘a’, ‘b’ and ‘c’ with at-most one ‘b’ and two ‘c’s allowed
*/
#include<bits/stdc++.h> 
using namespace std;
//approach 1: Recursion
int recur( int n , int b , int c ) {
    if( b < 0) 
        return 0 ; 
    if( c < 0 ) 
        return 0 ; 
    if ( n == 0 ) 
        return 1; 
    
    //for every position three choice 
    return  recur( n-1 , b -1 , c )  +  recur( n-1 , b , c -1 )  +  recur( n-1 , b , c ) ; 

    
}
int main(){
	int t; 
	cin>>t;
	while( t--){
	    int n;
	    cin>> n;
	    int ans = 0 ;
	    ans = recur( n , 1 , 2 ) ; 
	    /*
	    approach 2 
	    ans = 1; //all a
	    ans += n ;//1 b
	    ans += n ;//1 c
	    ans = ans + (n*(n -1)) / 2; // 2 c's 
	    ans = ans + (( n * (n -1) * (n - 2))  / 2 );// 1 b, 2 c's 
	    ans = ans + n * (n -1) ; // 1 c, 1 b ; 
	    */
	    cout<< ans <<"\n"; 
	}
	return 0;
}