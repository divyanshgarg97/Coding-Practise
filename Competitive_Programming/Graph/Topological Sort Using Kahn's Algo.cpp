//topological sort:- can be used to deadlocks in operating system
// work best when dependencies , like if I can start 4 only after 1 , 1----->4 means first 1 to be completed before going to 4
// check out example from codencode video tutorial
// to reach 7 , all 1,2,3,4,5,6 should have completed before 7
// thus topological sort will give me this type of ordering like above example
// there can be more than 1 topological ordering for same graph
// one observation with topological ordered set that we will get is , when we write,all nodes in according to topological sort and 
//then if I draw all edges according to graph given than all edges will be going forward always.,thus all edges will be from left to right
// Topological sort is for Directed Graphs (obviously)

//kahn's algo , very easy O(V+E)
// for each iteration,we will choose a node with 0 In-degree(means incoming edges to that node)
// basically to choose a node which have No dependency(In-degree 0)
// OR All its dependencies is already computed(All its edges coming from others is already removed)

// Algorithm Explanations:-
// 1. Start from any node with In-degree = 0
// 2. For each node that we choose from step 1 ,
//    2.1 We will remove all edges going outside from it
//    2.2 Add that node to topological sorting
// 3. Continue step 1 and step 2
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
#define space " "
int dx[] ={-1,0,1,0};int dy[] ={0,1,0,-1};
using namespace std;
//----------------------------------------------//
int t;
vector<int> arr[100];
vector<int> res;
int in[100];
void kahn(int n){
    queue<int> q;// to store nodes with In-degree =0
    for(int i=1;i<=n;i++){
        if(in[i] ==0)
            q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        res.pb(cur);
        for(int node : arr[cur]){
            in[node]--;
            if(in[node]==0)
                q.push(node);
        }
    }
    cout<< "Topological Sorting" << endl;
    for(int node:res){
        cout<< node << space;
    }
}
int main(){
    IOS
    int n,m,x,y;
    cin>>n>>m;
    FOR1(i,m){
        cin>>x>>y;
        arr[x].pb(y);
        in[y]++;
    }
    kahn(n);
}
