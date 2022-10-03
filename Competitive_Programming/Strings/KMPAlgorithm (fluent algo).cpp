#include<bits/stdc++.h>
using namespace std;
auto kmpPreprocess(string p){
	int n = p.length() ; 
	vector<int> pi(n,0);
	int l;
	for(int i= 1; i < p.length() ; i++ ){
		l = pi[i-1];
		while(l > 0 && p[i] != p[l])
			l = pi[l-1];
		if(p[i] == p[l])
			++l;
		pi[i] = l ;
	}
	return pi;
}
using namespace std; 
int main(){
    string s,p;
	int prev = 0, count = 0,l ;
	cin>> s >> p;
	p = p + '#';
	vector<int> pi = kmpPreprocess(p); 
	for(int i = 0; i < s.length(); i++ ){ //will begin from 0 because it might happen that first s = xyxyxyxyxyxyxy and p = xyxyxyxyyy
		l = prev ; 
		while( l > 0 && s[i] != p[l])
			l = pi[l-1];
		if( s[i] == p[l])
			l++; 
		prev = l ;
		if( l == p.length() - 1) // -1 as '#' was also added
			++count;
	}
	for(int i = 0 ; i < pi.size() ; i++ ) 
	    cout<< pi[i];
	cout<< count; // no . of occurences of p in s
}