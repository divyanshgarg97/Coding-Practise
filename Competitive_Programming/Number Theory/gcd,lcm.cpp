#include<bits/stdc++.h> 
#define ll long long
#define MOD 1000000007 
using namespace std; 
int gcd(int a ,int b ) {
	if(b == 0) return a;
	return gcd(b,a%b);
}
//extended gcd add later
int lcm(int a,int b){
	return (a*b) /gcd(a,b);
}
int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

}