#include<bits/stdc++.h> 
using namespace std; 
int binary_search_index(vector<int> a,int find) {
    int n = a.size(); 
    int l = 0 ; 
    int r = n - 1; 
    while( l <= r ) {
        int mid= r +(l-r ) / 2; 
        if( a[mid] == find){
            return mid;
        }
        else if(a[mid] < find){
            l = mid + 1; 
        }
        else 
             r = mid - 1; 
    }
    return l; 
}
int main(){
    vector<int> a = {1,2,4,5};
    for( int find = 0 ; find <= 7 ; find++ ) {
        int ans;
        ans = binary_search_index( a , find); 
        if( a[ans] == find) 
            cout<< "found the value and returned the index where it is" ; 
        else 
            cout<<"Not found , ans is the index where it should be if it was a part of the array";
        cout<< ans << " ";
    }
}