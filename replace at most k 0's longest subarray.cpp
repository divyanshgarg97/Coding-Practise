/*Function to find the maximum sequence of continuous 1's by replacing atmost k 0's by 1 using sliding window technique.*/
#include<bits/stdc++.h>
using namespace std;
void findans( int * a , int n,int k ){
    int high = 0, low = 0 , anse= 0 , anss = 0 ; 
    int zeroin = 0 ;
    int current = 0 ;
    int maxyet = 0 ;
    for( high = 0 ; high < n ; high ++ ){
        if( a[high] == 1){
            current ++; 
            if( current > maxyet ) {
                maxyet = current;
                anse = high ; 
                anss = low ; //**
            }
        }
        else{
            zeroin ++ ;
            current ++ ; 
            if( zeroin > k ) {
                while( a[low ] != 0  && low < high ) {
                    current -=1;
                    low ++ ; 
                }
                current--;
                low++; 
                zeroin -- ; 
            }
            else{
                //if i can add
                current ++ ; 
                if( current > maxyet) {
                    anse = high ; 
                }
            }
        }
    }
    cout<< anss << " " << anse << "\n"; 
}
int main()
{
	int arr[] = { 1, 1, 0, 1, 1, 0, 1, 1, 1, 1,0,0 };
    int n = sizeof(arr) / sizeof( arr[0]);
    findans(arr, n,0);
    findans(arr, n, 1) ;
    findans(arr, n , 2) ;
    findans(arr, n ,3) ;
	return 0;
}