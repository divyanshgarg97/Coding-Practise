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
#define endll '\n'
#define space " "
#define INF 1000000000
#define D(x) cout << #x " = " << (x) << endl
int dx[] ={-1,0,1,0};int dy[] ={0,1,0,-1};
using namespace std;
//----------------------------------------------//
int t;
int main(){
    IOS
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll mat[n][n];
        ll sum[n][n];
        int m = n;
        for(int i= 0;i<n;i++){
            for(int j= 0 ; j< m;j++){
                cin>>mat[i][j];
                sum[i][j] = mat[i][j];
            }
        }
        for(int i = 1 ; i< n;i++)
            sum[i][0]+=sum[i-1][0];
        for(int i= 1;i<m;i++)
            sum[0][i]+=sum[0][i-1];
        for(int i=1;i<n;i++){
            for(int j = 1; j<m;j++){
                sum[i][j] = sum[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        }
    }
}




















