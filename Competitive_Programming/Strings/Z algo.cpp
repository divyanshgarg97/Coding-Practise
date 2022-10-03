// #include<bits/stdc++.h> 
// #define ll long long
// #define MOD 1000000007 
// #define FOR(i,n) for(ll i = 0 ; i < n ;i++) 
// #define FOR1(i,n) for(ll i = 1; i<= n;i++)
// using namespace std; 
// auto z_algo(string str){
//     ll len = str.length();
//     ll l = 0 ; 
//     ll r = 0 ; 
//     vector<ll > z(len);
//     for(ll i = 1; i < len ; i++){
//         if( i > r ) {
//             l = r = i; 
//             while( r < len && str[r] == str[r-l])
//                 r++;
//             z[i] = r - l;
//             r--;
//         }
//         else{
//             ll idx = i - l ;
//             if(i + z[idx] <= r){
//                 z[i] = z[idx];
//             }
//             else{
//                 l = i; 
//                 while( r< len && str[r] == str[r-l])
//                     r ++ ; 
//                 z[i] = r - l ; 
//                 r--;
//             }
//         }
//     }
//     return z;
// }
// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     string str; 
//     cin>>str;
//     auto z = z_algo(str);
//     for(auto i:z)
//         cout<< i << " ";
// }
#include<bits/stdc++.h> 
#define ll long long
#define MOD 1000000007 
#define FOR(i,n) for(ll i = 0 ; i < n ;i++) 
#define FOR1(i,n) for(ll i = 1; i<= n;i++)
using namespace std; 
auto z_algo(string str){
    ll len = str.length();
    ll l = 0 ; 
    ll r = 0 ; 
    vector<ll > z(len);
    for(ll i = 1; i < len ; i++){
        if( i > r ) {
            l = r = i; 
            while( r < len && str[r] == str[r-l])
                r++;
            z[i] = r - l;
            r--;
        }
        else{
            ll idx = i - l ;
            if(i + z[idx] <= r){
                z[i] = z[idx];
            }
            else{
                l = i; // reset the l and search for new window
                while( r< len && str[r] == str[r-l])
                    r ++ ; 
                z[i] = r - l ; 
                r--;
            }
        }
    }
    return z;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str,pat; 
    cin>>str>>pat;
    string total = pat + '$' + str;
    auto z = z_algo(total);
    for(ll i = pat.length() + 1 ; i < z.size(); i++ ) {
        if( z[i] == pat.length()) {
            cout<< ( i - pat.length() - 1) << "\n";
        }
    }
    cout<< "\n Check for z values"; 
    cout<< "\n";
    FOR(i,z.size()){
        cout<< z[i] <<" ";
    }
    cout<< "\n";
}