//kruskal is greedy algo, to find MST of a Weighted graph
// first sort all the edges based on their weights in ascending order
// take edge one by one such that if I take edge a---b then a cannot be reached from any path from b ,bassically a and b should not be connected(by connected I mean , no path should exist using which I can reach one from another)
// why Not connected condition was taken?
// If their exist a already path from node A to node B , then adding A---B will make cycle.To get rid of a cycle , we should remove one edge from it.As all edges are sorted according to weight then previous values must be smaller than A---B weight, hence remove A---B only , or just don't add this Edge.

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
const int maxN = 101;
//vector<int> adjList[maxN];
struct edge{
    int a,b,w;
};
edge arr[100000];
int par[10001];
bool mycomp(edge a,edge b){
    if(a.w < b.w) return true;
    return false;

}
int Find(int a){
    if(par[a]==-1)
        return a;
    return par[a] = Find(par[a]);
}
void Merge(int a ,int b ){//union function
    par[a]=b;
}
int main(){
    IOS
    int sum = 0;
    int n,m,x,y,w;
    cin>>n>>m;
    // initialize parent
    for(int i =1 ;i<=n;i++) par[i] =-1;
    for(int i=0;i<m;i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].w;
    }
    sort(arr, arr + m,mycomp);
    int para= -1;
    int parb= -1;
    for(int i =0;i<m;i++){
        para=Find(arr[i].a);
        parb=Find(arr[i].b);
        if(para !=parb){ // were not connected till now , so connect them and add their sum
            sum +=arr[i].w;
            Merge(para,parb);// ,y);
        }
    }
    cout<< sum << endl;
}

























