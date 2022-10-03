#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1e9+7
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define for0(i,n) for(ll i = 0 ; i < n ;i++)
#define for1(i,n) for(ll i = 1; i<= n;i++)
#define for2(i,s,e) for(ll i = s ; i<e; i++)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<ii>
#define vll vector<pair<ll,ll> >
#define endl '\n'
#define space " "
#define INF 1000000000
#define D(x) cout << #x " = " << (x) << endl
int dx[] ={-1,0,1,0};int dy[] ={0,1,0,-1};
using namespace std;
//----------------------------------------------//
int t;
const int maxN = 1e3 + 2;
int N , M;
bool vis[maxN][maxN];
int dist[maxN][maxN];
bool isValid(int x,int y){
    if(x<1 || x > N || y < 1|| y>M)
        return false;
    if(vis[x][y]) // already visited
        return false;
    return true;
}

void bfsGrid(int srcX ,int srcY){
    queue<ii> q;
    q.push({srcX,srcY});
    dist[srcX][srcY]=0;
    vis[srcX][srcY] = 1;
    while(!q.empty()){
        int currX = q.front().ff;
        int currY = q.front().ss;
        q.pop();
        for(int i = 0 ; i < 4;i++){
            if(isValid(currX + dx[i], currY + dy[i])){
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                dist[newX][newY]= dist[currX][currY]+1;
                vis[newX][newY] =1;
                q.push({newX,newY});
            }
        }
    }
}

//void bfsGeneral(int src){
//    queue<int> q;
//    q.push(src);
//    dist[src]=0;
//    vis[src] = 1;
//    while(!q.empty()){
//        int curr = q.front();
//        q.pop();
//        for(int node : arr[curr]){
//            if(vis[node] ==0) {
//                dist[node] = dist[node] + dist[curr];
//                vis[node] =1;
//                q.push(node);
//            }
//        }
//    }
//}
int main(){
    IOS
    cin>>t;
    while(t--){
    }
}


























