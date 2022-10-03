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
void update(index,L,R,val,time){
    if(index is out of range) return;
    if(L==R){
        tree[index].emplace_back(time,value);
        return;
    }
    update left child;
    update right child;
    int f= tree[index<<1][tree[index<<1].size()-1].second;
    int s = tree[index<<1|1][tree[index<<1|1].size()-1].second;
    tree[index].emplace_back(time,max(f,s));
}

int query(index,L,R,qL,qR,time){ // basically query this range at a particular time
    if(L > qR || R < qL) return -INF;
    if(L >=qL && R <=qR ){
        if(time > tree[index].size()-1].first)
            return tree[index][tree[index].size()-1].second;
        else{
            // binary search for best value
            int a= 0,b = tree[index].size()-1;
            while(a!=b){
                int mid = (a + b ) / 2;
                if( tree[mid].first <=time)
                    a = mid;
                else
                    b = mid -1;
            }
            return tree[index][mid].second;
        }
    }
    return max(query(index<<1,L,mid,qL,qR,time),query(index<<1|1,mid+1,R,qL,qR,time));
}



int main(){
    IOS
    cin>>t;
    while(t--){
    }
}

























