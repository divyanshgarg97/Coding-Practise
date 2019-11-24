/*
Input : a[] = {3, 10, 3, 11, 4, 5, 6, 7, 8, 12}
Output : 3 4 5 6 7 8
Input : a[] = {6, 7, 8, 3, 4, 5, 9, 10}
Output : 6 7 8 9 10
*/
#include<bits/stdc++.h> 
using namespace std; 
int main() {
    int t; 
    cin>> t; 
    while(t--){
        int n; 
        cin>> n;
        int a[n]; for(int i = 0 ; i < n;i++) cin>> a[i]; 
        vector<int> dp(n,1 ) ; //  dp[n]; 
        vector<int> prev(n , -1 ) ; // int prev[n];
        int max_val= INT_MIN; 
        int max_i = -1; 
        for( int i = 1; i < n;i++ ) {
            for( int j = 0 ;j < i ; j ++ ) {
                if( a[i] > a[j]  && dp[i] < dp[j] + 1 && abs(a[i] - a[j]) ==1){
                    dp[i] = dp[j] + 1;
                    prev[i] = j ; 
                    if( max_val < dp[i]){
                        max_val = dp[i];
                        max_i = i; 
                    }
                }
            }
        }
        vector<int> ans;
        int i = max_i;
        cout<< "printing the dp array "<<"\n"; 
        for( int i = 0 ; i< dp.size() ; i++ ) 
            cout<< dp[i]<<" ";
        cout<< "\n printing the prev array"<<"\n";
        for( int i = 0 ; i < prev.size() ;i++) 
            cout<< prev[i]<<" ";
        cout<< "\n";
        ans.push_back(a[max_i]);
        while( prev[i]!=-1){
            ans.push_back(a[prev[i]]);
            i = prev[i];
        }
        reverse(ans.begin() , ans.end() ) ; 
        for( i = 0 ; i < ans.size() ;i ++ ) cout<<ans[i]<<" ";
        cout<< "\n";
    }
}