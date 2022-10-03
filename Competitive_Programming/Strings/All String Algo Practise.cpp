#include<bits/stdc++.h> 
#define ll long long
#define MOD 1000000007 
#define FOR(i,n) for(ll i = 0 ; i < n ;i++) 
#define FOR1(i,n) for(ll i = 1; i<= n;i++)
#define FOR2(i,s,e) for(ll i = s ; i<e; i++) 
using namespace std; 
auto kmpPreprocess(string s ) {
	int n = s.length();
	vector<int> pi(n,0);
	for(int i = 1; i < n;i++) {//pi[0] = 0 always
		l = pi[i-1];
		while( l > 0 && s[i] != s[l])
			++l;
		if(s[i] == s[l])
			++l;
		p[i] = l;
	}
	return pi;
}
auto zPreprocess(string s){
	int n = s.length();
	vector<int> z(n,0);
	int l = 0 , r = 0;
	//z[0]= 0 always 
	for(int i = 1 ; i < n ; i++ ){
		if( i > r ) {
			l = r = i ; 
			while( r < n && s[r] != s[r-l])
				++r;
			z[i] = r;
			r--;
		}
		else {
			int idx = i - l; 
			if(z[idx] + i <= r)
				z[i] = z[idx];
			else {
				l = i;
				while( r < n && s[r] != s[r-l])
					++r;
				z[i] = r; 
				r--;
			}
		}
	}
	return z; 
}
void manacharAlgo(string s) {
	int n = s.length();
	string t = '$' + '#';
	vector<int> v(t.length(),0);
	for(int i = 0 ; i < n - 1; i++ ) {
		t = t + s[i] +'#';
	}
	t = t + s[n-1] + '@';
	int c = 0 ; // centre 
	int r = 0; 
	int mirr = 0 ; 
	for(int i = 1 ; i< t.length()-1 ;i++) { // begin from 1st
		mirr = 2 * c - i;//where 'i' in accordance with main pallindrome kaa centre which is 'c'
		if( i < r ) {
			v[i] = min (r - i ,p[mirr])
		}
		while( t[i + (1 + v[i])] == t[i - (1+ v[i])])
			v[i]++;
		if(i + p[i] > r ){ 
			r = i + p[i];
			c=i;
		}
	}
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
	#endif
	//z algo
	string s,p;
	cin>>s>>p;
	int l=0,r=0;
	string t = p + '$' + s;
	int n= t.length();
	vector<int> z = zPreprocess(t);
	int count = 0 ; 
	for(int i = p.length()+1 ; i < n; i++ ) {
		if(z[i] == p.length())
			count++;
	}
	cout<< count<< "\n";

	// kmp algo
	string s,p;
	cin>> s >> p ;
	p = p + '#';
	auto pi = kmpPreprocess(p);
	int prev = 0,l = 0;
	int count = 0;
	for(int i = 0 ; i < s.length() ; i++){
		l = prev;
		while(l > 0 && s[i] != s[l])
			l = pi[l-1];
		if(s[i] == p[l])
			++l;
		if(l == p.length() - 1)
			count ++ ; 
		prev = l;
	}

	// Manachar's algo
 	// done function
}