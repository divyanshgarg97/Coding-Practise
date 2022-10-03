#include <iostream>
#include<bits/stdc++.h> 
using namespace std;
int main() {
    string s = "divyansh";
    map<string,int> mp;
    for( int i = 0 ; i < s.length(); i ++ ) {
        mp[s.substr(i,s.length())] = i; 
    }
    for( auto i : mp){
        cout<< i.first << " "<<i.second;
        cout<< "\n";
    }
	return 0;
}