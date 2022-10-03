// what can we do using policy based data structures?
// 1. add/remove elements(just like we do in set)
// 2. no. of elements < x (order_by_key)
// 3. kth smallest element (find_by_order)
// 4. Min/Max elements
// All the above 4 can be done in O(logN) time
// best is to use notes for theory , already written
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> // added for pbds
#include<ext/pb_ds/tree_policy.hpp> // added for pbds
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
using namespace __gnu_pbds;// for pbds
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//  int ->int type, less<int> to tell ascending order storage
//----------------------------------------------//
int t;
//int main(){
//
//    pbds A;
//
//    //Add elements in any random order
//    A.insert(11);A.insert(1);A.insert(5);A.insert(3);A.insert(7);A.insert(9);
//
//	//Total contents
//	cout << "1, 3, 5, 7, 9, 11" << endl;
//
//	//1. K-th smallest element ( *A.find_by_order(k-1) )
//	int k = 3;
//	cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//
//	//2. NO OF ELEMENTS < X ( A.order_of_key(X) )
//	int X = 9;
//
//	cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;
//
//	//3. DELETE Elements ( A.erase )
//    cout << "Deleted 3" << endl;
//    A.erase(3);
//
//    //Total contents
//	cout << "1, 5, 7, 9, 11" << endl;
//
//    cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;
//
//    //4 . NEXT BIGGER/SMALLER ELEMENT than X ( *A.upper_bound(X) )
//    X = 8;
//
//    cout << "Next greater element than " << X << " is " << *A.upper_bound(X) << endl;// greater as we made it a less<int> type pbds
//    //cout<< "Next smaller element than " << X << "is" << *A.upper_bound(X) << endl;// if pbds was made of "LESS TYPE"
//
//
//	return 0;
//
//
//}
int main(){
    // to count number of inversions in array using pbds
    IOS
    pbds set1;
    int n;
    cin>>n;
    int ans = 0 ;
    for(int i =0 ;i < n;i++ ) {
        int x,y;
        cin>>x;
        set1.insert(x);
        y = set1.order_of_key(x);
        ans += (i - y) ;
    }
    cout<< ans;

}
















