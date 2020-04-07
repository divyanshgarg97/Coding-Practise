#include<bits/stdc++.h> 
using namespace std; 
int main() {
    vector<int> v( 20,1) ; 
    for( int i = 0 ; i < 5; i++ ){
        v[i] = v[i] + 2, v[i+ 2] = v[i+2] + 2; 
    }
    for(int i = 0 ; i< 20 ;i++ ) 
        cout<< v[i] << " ";
    return 0 ;
}class Solution {
public:
    /*
    struct mycomp2{
        bool operator()(vector<int> A, vector<int> B ) {
            if( A[2] < B[2])
                return true;
            else if (A[2] > B[2])
                return false;
            else{
                if (A[1] > B[1]){
                    return false;
                }
            }
            return true;
        }
    };
    bool mycomp(vector<int> A, vector<int> B ) {
        if( A[2] < B[2])
            return true;
        else if( A[2] > B[2])
                return false;
        else {
            return false;
        } 
        return true;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //sort all the trip values according to end location
        int n = trips.size();
        if( n == 0 ) 
            return true; 
        sort( trips.begin(),trips.end(),mycomp2());
        //sort( trips.begin(),trips.end(),mycomp);
        int lcap = trips[0][0] ;
        int startl= trips[0][1];
        int endl = trips[0][2];
        for(auto i = 1; i < trips.size();i++ ) {
            int cap = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];
            if(start  < endl) {
                int check = lcap + cap; 
                if(check > capacity)
                    return false;
                else {
                    if (end > endl){
                        lcap = cap ; 
                        startl = start; 
                        endl = end;
                    }
                    else if( end < endl){
                        //continue with same variables
                    }
                }
            }
            else{
                lcap = cap;
                startl = start; 
                endl = end;
            }
        }
        return true;
    }
    */
    /*
    add values in between complete range
    bool carPooling(vector<vector<int>>& trips, int capacity){
        int n = trips.size();
        int a[1001];
        memset(a,0,sizeof(a));
        for( int i = 0 ; i < n;i++){
            for( int j = trips[i][1]; j < trips[i][2] ; j++){
                a[j] = a[j] + trips[i][0];
            }
        }
        for( int i = 0 ; i < 1001 ; i++)
            if( a[i] > capacity)
                return false;
        return true;
    }
    */
    //no need for complete range, firt and last will suffice
    bool carPooling(vector<vector<int>>& trips, int capacity){
        int n = trips.size();
        int a[1001];
        memset(a,0,sizeof(a));
        for( int i = 0 ; i < n;i++){
            a[trips[i][1]] += trips[i][0];
            a[trips[i][2]] -= trips[i][0];
        }
        int check = 0 ; 
        for( int i = 0 ; i < 1001 ; i++){
            check += a[i]; 
            if( check > capacity )
                return false;
        }
        return true;
    }
    //can use map also , but time will be nLogn
};