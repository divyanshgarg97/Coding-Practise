//SpaceComplexity:- NlogN(as any node can be part of logN nodes)
//Time Complexity:-

// question :-
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
const int maxN = 1e5+2;
int arr[maxN];
vector<int> st[4*maxN];
void build(int si,int ss,int se){
    if(ss==se) {
        st[si].pb(arr[ss]);
        return;
    }
    int mid = (ss+se)>>1;
    build(si<<1,ss,mid);
    build(si<<1|1,mid+1,se);
    int i = 0 ;
    int j = 0 ;
    while(i<st[si<<1].size() && j<st[si<<1|1].size()){
        if(st[si<<1][i] <= st[si<<1|1][j])
            st[si].pb(st[si<<1][i]) , i++;
        else
            st[si].pb(st[si<<1|1][j]) , j++;
    }
    while(i<st[si<<1].size())
        st[si].pb(st[si<<1][i]) , i++;

    while(j < st[si<<1|1].size())
        st[si].pb(st[si<<1|1][j]), j++;
}
int query(int si,int ss ,int se,int qs ,int qe,int k){
    if( ss > qe || se < qs)
        return 0;
    if( ss>= qs && se <=qe) {
        int res = lower_bound(st[si].begin(),st[si].end(),k) - st[si].begin(); // first index which is greater than value k-1
        // for eg :- array values:  2 4 5 7 9
        //           array index:-  0 1 2 3 4  and k = 5 , Lower bound will return index = 2 , which is required number of elements less than 5
        //                                     and k = 3, lower bound will return index = 1, which is required number of elements less than 3

        return res;
    }
    int mid = (ss+se)>>1;
    int l = query(si<<1,ss,mid,qs,qe,k);
    int r = query(si<<1|1,mid+1,se,qs,qe,k);
    return (l+r);
}
int main(){
    IOS
    int n,q,l,r,k;
    cin>> n>> q;
    for(int i= 1 ;i <=n;i++ )
        cin>> arr[i];
    build(1,1,n);
    while(q--) {
        cin>> l>> r>>k;
        cout<< query(1,1,n,l,r,k)<<endl;
    }
}




















