#include<bits/stdc++.h> 
#define ll long long
#define MOD 1000000007 
using namespace std; 
int reset[100000];
string t,p;
void kmppreprocess(){
	int n = p.length();
	reset[0] = -1;
	int i = 0 , j = -1;
	while(i < n){
		while( j >= 0 && p[i] !=p[j])
			j = reset[j];
		i ++ , j ++ ;
		reset[i] = j;
	}
}
void kmp(){
	int n = t.length(), m = p.length();
	int i = 0,j = 0 ; 
	while(i < n ) {
		while( j >=0 && t[i] != p[j])
			j = reset[j];
		i++,j++;
		if(j == m) {
			cout<< "found at index" << i - j << "\n";
			j = reset[j]; // for next match finding
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin>>t>>p;
    clock_t t0 = clock();
    kmppreprocess();
    kmp();
    //clock_t t1 = clock();
    // to check runtime internally of a function
  	// 	clock_t t0 = clock();
  	// 	function1();
 	// clock_t t1 = clock();
  	//printf("Runtime = %.10lf s\n\n", (t1 - t0) / (double) CLOCKS_PER_SEC);
}