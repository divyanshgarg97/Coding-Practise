#include<bits/stdc++.h> 
#define ll long long
#define MOD 1000000007 
#define FOR(i,n) for(ll i = 0 ; i < n ;i++) 
#define FOR1(i,n) for(ll i = 1; i<= n;i++)
#define FOR2(i,s,e) for(ll i = s ; i<e; i++) 
int timer; 
int S[100];//starting time
int T[100]; // terminating time
int FT[200];//flattened tree storage
//basically we will store in S and T with index = node and in FT , we will store with index = time and store which node was there for this time

//way to implement dfs when we don't want to keep a visited array, is give parent also
vector<int> ar[100]; // adjacency list representation of graph
void dfs(int node, int par) {
	S[node] = timer;//the time we entered this node, store it
	FT[timer] = node; //at time ,timer , which node was we working with
	timer ++;//increase timer
	for(int child : ar[node]) // to avoid child to go to its parent as parent.
		if( child != par)
			dfs(child,node);
	T[node] = timer;
	FT[timer]= node;
	timer++;
}
using namespace std; 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,a,b;
    cin>>n;
    for(int i = 1; i < n ;i++ ) {
    	cin>> a>> b; 
    	ar[a].push_back(b);
    	ar[b].push_back(a);
    }
    timer = 1; 
    dfs(1,-1);
}