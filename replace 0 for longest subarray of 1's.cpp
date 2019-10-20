/*Given an array of 0s and 1s, find the position of 0 to be replaced with 1 to get longest continuous sequence of 1s.
Expected time complexity is O(n) and auxiliary space is O(1).*/

#include<bits/stdc++.h>
using namespace std;
void findans( int * a , int n){
    int high = 0 ;
    int low = 0 ;
    int index = -1 ;
    int maxsumyet= 0 ;
    int current=0 ;
    int zero = 0 ;// to handle testcase like arr3
    if( a[0]==0 ){
        index = 0 ;
        current = 1; 
        maxsumyet = 1; 
        zero =1;
    }
    else{
        current =1; 
        maxsumyet = 1; 
    }
    for( high= 1 ;high < n;high++ ) {
        if( a[high] == 1){
            current++;
        }
        else if( a[high] ==0){
            while( a[low] != 0 && low <high && zero == 1){
                current = current -1;
                low ++;
            }
            if( low < high && zero ==1){
                current -=1;
                zero =0 ;// as previous zero deleted,can avoid this
            }
            current = current + 1;
            zero =1; //as new zero added ,can avoid this
            if( current > maxsumyet){
                maxsumyet = current; 
                index = high;
            }
        }
    }
    cout<< index; 
    cout<< "\n";
}

int main()
{
    int arr1[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
    int arr2[] =  {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
    int arr3[] =  {1, 1, 1, 1, 0};
    int n1 = sizeof(arr1) / sizeof( arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3 ) / sizeof(arr3[0]);
    findans(arr1, n1);
    findans(arr2, n2);
    findans(arr3, n3);
    return 0;
}