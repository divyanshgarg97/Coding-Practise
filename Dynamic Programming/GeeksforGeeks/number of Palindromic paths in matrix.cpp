//without dp
#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
bool check( int sr, int sc , int er , int ec , int m , int n ) {
    if( sr >-1 && sr < m && sr<=er && sc <= ec && er > -1 && er < m  && sc > -1 && sc < n && ec> -1  && ec < n ){
        return true; 
    }
    return false;
}
int go( vector<vector<char> > a , int sr, int sc , int er , int ec,int m , int n ) {
    
    //base cases
    if(!check ( sr, sc, er, ec, m , n )) 
        return 0 ; 
    if( a[sr][sc] !=a[er][ec])
        return 0 ; 
    // adjacent as pallindrome can be odd or even 
    if( abs((sr - er )+(sc- ec)) <= 1 ) // 1 is for adjacent and < 1 is for same 
        return 1; // that is adjacent also same found so count will be added for this recursion hence return 1 
    
    int res = 0 ; 
    res = res + go ( a,sr + 1 ,sc , er , ec-1,m,n) ; 
    res = res + go( a,sr+1, sc, er-1 , ec,m,n) ; 
    res += go  (a,sr, sc+1, er, ec-1,m,n ) ; 
    res += go(a, sr, sc+1, er-1, ec,m,n) ; 
    return res;
}
int main()
 {
	//code
	int t; 
	cin>> t; 
	while(t--) {
	    int m , n ; 
	    cin>> m >> n ;
	    vector<vector<char > > a ( m , vector<char > (n , 'a'));// a[m][n];
	    for( int i= 0 ; i< m ;i++ ) 
	        for( int j = 0 ;j < n;j++ ) 
	            cin>> a[i][j];
	    int ans = 0 ; 
	    cout<< go( a , 0 , 0 , m-1 , n -1,m,n ) <<"\n"; 
	    
	}
	return 0;
}


