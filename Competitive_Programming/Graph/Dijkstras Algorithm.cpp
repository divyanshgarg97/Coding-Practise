// time complexity:- O(V+ElogV) when using priority queue
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
const int maxN = 1e5 + 2;
vector<ii> arr[maxN];// pair as now We need both connection and weight of node
// (node,weight) is stored in pair
int main(){
    IOS
    int n,m,x,y,w;
    cin>>n>>m;
    for(int i= 0 ; i< m; i++ ) {
        cin>> x >> y >> w;
        arr[x].pb({y,w}); // (node,weight) is stored here
        arr[y].pb({x,w});
    }
    priority_queue<ii,vii,greater<ii> > pq; // (weight, node) is stored here as pq will decide on the basis of first element
    vector<int> dist(n+1,INF); // INF is 10^9 , basically any value which cannot be the distance between two nodes
    int src= 1;
    pq.push({0,src});
    dist[src] = 0 ;
    while(!pq.empty()){
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();
        for(ii node : arr[curr]){
            if(curr_d + node.second  < dist[node.first] ) {
                dist[node.first] = curr_d + node.second;
                pq.push({dist[node.first], node.first});
            }
        }
    }
    for(int i = 1; i <= n;i++ ) {
        cout<< dist[i] << space;
    }
}
