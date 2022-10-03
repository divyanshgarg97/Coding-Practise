#include<bits/stdc++.h> 
#define ll long long
#define MOD 1000000007 
int p[MOD];
int r[MOD];
using namespace std; 
//naive
int find(int a ){
	if(p[a] < 0)
		return a;
	return find(p[a]);
}
void uniona(int a ,int b ) {
	a= find(a);
	b= find(b);
	if( a== b) return;
	else p[a] = b; 
}

// path compression
int findpc(int a){
	if(p[a] < 0) 
		return a;
	return p[a] = find(p[a]);
}

void unionpc(int a ,int b ) {
	a = find(a);
	b = find(b);
	if( a==b ) return;
	else p[a] = b; 
}

//unionbyrank with path compression
void findur(int a){
	if( p[a] < 0) return a; 
	return p[a] = find(p[a]);
}
void mergeur(int a ,int b ) {
	a = find(a);
	b = find(b);
	if(a ==b ) return ;
	if( r[a] > r[b])
		p[b] = a,r[a]+=r[b];
	else
		p[a] = b,r[b] += r[a];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
}