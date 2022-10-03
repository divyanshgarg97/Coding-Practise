//find longest palindromic substring in O(n) time
#include<bits/stdc++.h> 
#define ll long long
#define MOD 1000000007 
#define FOR(i,n) for(ll i = 0 ; i < n ;i++) 
#define FOR1(i,n) for(ll i = 1; i<= n;i++)
#define FOR2(i,s,e) for(ll i = s ; i<e; i++) 
void manacharAlgo(string s) {
	string t = '$' + '#'; 
	int n = s.length(); 
	FOR(i,n-1)
		t = t + s[i] + '#';
	t = t + s[n-1] + '@';
	int c = 0; // centre of main palindrome
	int r = 0 ; // right boundary of main palindrome
	int p[t.length()];
	memset(p,0,sizeof(p)); 
	for( int i = 1; i < t.length() - 1; i ++ ) {
		int mirr = 2 * c - i;  //when I consider 'i' as centre and we want where it lie in according to 'c' ( which is main of main palindrome),so that if main palindrome ke andar lie karein toh ,we can use value from it , and later expand if needed

		if(i < r)//does i lie within r,i.e. 'i' is greater value than main palindrome ke r se , 
			//means 'i' bahar hai main palindrome( so definitely we cannot use it to update value at i) 
			p[i] = min(r - i , p[mirr]);
		
		// trying to expand by comparing the characters at the centre
		while(t[i + (1 + p[i] )] == t[i - (1 + p[i])])
			p[i] ++;
		if( i + p[i] > r ) {//basically if palindrome centred at 'i' and pallindrome length at 'i' is greater than centre of main palindrome, then we update our main palindrome
			// yes then update both c and r 
			c = i ; 
			r = i + p[i];
		}
	}
}
using namespace std; 
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  string s; 
  cin>> s; 
  manacharAlgo(s);
}