#include<bits/stdc++.h> 
#define ulli unsigned long long int
using namespace std;
int freq[1000001];
long long int block= 0 ; 
unsigned long long int ans[200001];
int a[200001];
unsigned long long int  power = 0;
struct query{
    int l ; 
    int r; 
    int i ; 
};
bool comp(query a, query b ) {
    if(a.l/ block != b.l/ block){
        return a.l/ block < b.l/block;
    }
    else
        return a.r < b.r;
}
void add(int pos) {
    int element = a[pos]; 
    int pref = freq[element];
    int newfreq = ++freq[element];
    power = power - (ulli ) (pref * pref * element);
    power = power + (ulli)(newfreq * newfreq * element);
}
void remove(int pos) {
    int element = a[pos]; 
    int pref = freq[element]; 
    int newfreq = --freq[element];
    power = power - (ulli)(pref * pref * element); 
    power = power + (ulli)(newfreq* newfreq * element);
}
query q[200001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , t; 
    cin>> n>> t; 
    block = ceil((double)sqrt(n));
    for( int i = 0 ;i < n;i++ ) cin>> a[i];
    //store all the queries
    for( int i = 0 ; i < t; i++ ) {
        cin>>q[i].l;
        cin>>q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].i = i;
    }
    sort(q,q + t,comp);
    int ml = 0 , mr = -1; 
    for( int i = 0 ; i< t; i ++ ) {
        int l = q[i].l;
        int r = q[i].r;
        // extend
        while(ml > l ){
            ml--;
            add(ml);
        }
        while( mr < r ) {
            mr++;
            add(mr);
        }
        
        //reduce 
        while( ml < l){
            remove(ml);
            ml++; 
        }
        while( mr > r ) {
            remove(mr);
            mr--;
        }
        ans[q[i].i] = power; 
    }
    for(int i = 0 ; i < t; i++ ) 
        cout<< ans[i]<<"\n"; 
}