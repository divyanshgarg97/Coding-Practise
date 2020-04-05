//bucket sort for combined positive and negative numbers,same as positive numbers only just make one more array of vectors for negative and store in them by making them positive
//do same thing in it,ie storing in buckets(now descending order or dont do descending , at the time of joining store from end for negative number array) and then sorting every bucket and later combine by adding negative sign 
//bucket sort for positive numbers

#include<bits/stdc++.h> 
using namespace std;
void bucketSort(float arr[], int n ) {
    vector<float> b[n]; // create n empty buckets 
    for( int i = 0; i < n ;i++ ) {
        int bi = n * arr[i]; 
        b[bi].push_back(arr[i]);
    }
    for(int i = 0 ; i < n ;i++ ){
        sort(b[i].begin(),b[i].end());
    }
    int index = 0 ; 
    for(int i = 0 ; i< n;i++ ){
        for( int j = 0 ;j < b[i].size();j ++ ){ 
            arr[index++] = b[i][j];
        }
    }
}
int main() { 
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bucketSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    for (int i=0; i<n; i++) 
       cout << arr[i] << " "; 
    return 0; 
} 