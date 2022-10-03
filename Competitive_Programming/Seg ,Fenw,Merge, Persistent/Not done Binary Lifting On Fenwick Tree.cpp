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
int Find(int k){
    //binary lifting on fenwick tree
    int curr = 0,ans =0,prevsum=0;
    //curr is lower index
    for(int i = log2(n);i>=0;i--){
        if(fen[curr+(1<<i)]+prevsum< k){
            curr = curr + (1<<i);
            prevsum += ft[curr];
        }
    }
    return (curr+1); // will find me lower_bound for particular prefix value
    // eg:- I want to find lower_bound for prefix value = 10
    // basically I want to find the minimum index at which prefix sum becomes >=10
}
int main(){
    IOS
    cin>>t;
    while(t--){
    }
}

























