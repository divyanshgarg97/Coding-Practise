// incorrect not done yet
// will use dfs for cycle detection
// main thing here to notice is we need to check if already visited in dfs and visited should be in current dfs call
// in undirected , we used a global visited array and using it,we find out cycle
// in directed , we use visited array too , but consider it cycle only if found visited in current dfs traversal
// i.e. we will make the node true when we visit it and make it false when completely exhausted
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define forz(i,n) for(ll i = 0 ; i < n ;i++)
#define foro(i,n) for(ll i = 1; i<= n;i++)
#define fort(i,s,e) for(ll i = s ; i<e; i++)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<ii>
#define vll vector<pair<ll,ll> >
#define endll '\n'
#define space " "
#define INF 1000000000
#define D(x) cout << #x " = " << (x) << endl
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
using namespace std;
//----------------------------------------------//
int t;
const int maxN = 1e6+2;
vector<int> arr[maxN];
bool vis[maxN];
bool dfs(int node , int par) {
    vis[node] = true;
    for(int child : arr[node]) {
        if(vis[child] == true) {
            if(child!= par)
                return true;
        }
        else{
            if(dfs(child,node)== true)
                return true;
        }
    }
    vis[node] = false;
    return false;
}
int main(){
    IOS
    cin>>t;
    while(t--){
    }
}