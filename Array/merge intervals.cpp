#include <iostream>
#include<bits/stdc++.h>
using namespace std;
    bool mycomparator ( pair<int , int> a , pair<int, int> b ) {
        if( a.first > b.first) 
            return false;
        return true;
    }
int main() {
	//code
	int t; 
	cin>> t;
	while(t--){
	    int n;
	    cin>> n;
	    int a, b; 
	    vector<pair<int, int> > v; 
	    for( int i = 0 ;i<n ;i++ ) {
	        cin>> a>> b; 
	        v.push_back(make_pair( a, b ) );
	    }
	    sort( v.begin() , v.begin() + n, mycomparator);
	    stack<pair<int, int> > s; 
	    s.push(v[0]);
	    for( int i = 1; i< n;i++ ) {
	        pair<int, int> t = s.top() ; 
	        pair<int, int> check = v[i];
	        if( check.first <= t.second){
	            if( check.second >t.second){
	                t.second = check.second; 
	                s.pop();
	                s.push(t);
	            }
	            else{
	                //inside it , already top fully contains new upcoming interval
	            }
	        }
	        else if( check.first > t.second) {
	            s.push(check); 
	        }
	    }
	    vector<pair<int , int> > ans ; 
	    int mm = 1; 
	    while(!s.empty() ){
	        pair<int, int> t = s.top ();
	        s.pop();
	        mm++;
	        ans.push_back(t);
	    }
	    reverse( ans.begin() , ans.end());
	    for( int i = 0 ;i< ans.size()  ; i++ ) {
	        pair<int , int> t = ans[i];
	        cout<< t.first<< " "<<t.second<<" ";
	    }
	    cout<< "\n";
	}
	return 0;
}