#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define take_fast {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
int max(int a , int b , int c) {
    return max( a , max(b , c ) ) ;
}
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ; 
    cout.tie(NULL) ; 
    priority_queue<int > pq; 
    lli n;
    cin>>n;
    pq.push(1) ; pq.push(5) ; pq.push(10);pq.push(20);pq.push(100);
    lli ans=0;
    while( n >0){
        int temp = pq.top() ;
        //cout<< temp<< " ";
        while( (n / temp) >0){
            n -=temp;
            //cout<< ans <<" ";
            ans++;
        }
        pq.pop();
    }
    cout<<ans;
}