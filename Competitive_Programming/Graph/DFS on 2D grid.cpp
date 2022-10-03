#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR0(i,n) for(ll i = 0 ; i < n ;i++)
#define FOR1(i,n) for(ll i = 1; i<= n;i++)
#define FOR2(i,s,e) for(ll i = s ; i<e; i++)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<ii>
#define vll vector<pair<ll,ll> >
#define endl '\n'
#define INF 1000000000
#define D(x) cout << #x " = " << (x) << endl
int dx[] ={-1,0,1,0};int dy[] ={0,1,0,-1};
using namespace std;
//----------------------------------------------//
const int maxN= 1e3;
bool vis[maxN][maxN];
int N,M;// for row and column value
bool isValid(int x,int y){
    if(x<1 || x > N || y < 1|| y>M)
        return false;
    if(vis[x][y]) // already visited
        return false;
    return true;
}
void dfs1(int x,int y){ // don't use this in practise , lengthy to write ,use dfs2
    vis[x][y]=1;
    // write clockwise(better for remembering)
    if(isValid(x-1,y)) // up
        dfs1(x-1,y);
    if(isValid(x,y+1)) //right
        dfs1(x,y+1);
    if(isValid(x+1,y)) // down
        dfs1(x+1,y);
    if(isValid(x,y-1)) // left
        dfs1(x,y-1);
}
void dfs2(int x,int y){
    vis[x][y]=1;
    cout<< x<< " "<<y<<endl;
    for(int i=0;i<4;i++){
        if(isValid(x+dx[i],y+dy[i]))
            dfs2(x+dx[i],y+dy[i]);
    }
}
//void dfsGeneral(int x){
//    vis[x]=1;
//    for(auto i:adjList[x]){
//        if(!vis[i])
//            dfsGeneral(i);
//    }
//}
int main(){
    IOS
    cin>>N>>M;
    dfs2(1,1);
}

























