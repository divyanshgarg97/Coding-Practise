class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
        // write your code here
        //way1:- use extra space and map the values in it O(n) space , O(n) time
        // way2:simple XOR's wont work as both are odd types ,hence all cancelled everytime
        //way3:- store bits of everynumber and later % 3 of all,O(1)space and O(n) time
        // working
        int a[32]; 
        memset(a,0,sizeof(a));
        for( int i : A ) {
            for( int j =0 ;j<32; j ++ ) {
                a[j] = a[j] +  (int)(i & 1); 
                i = i >> 1; 
            }
        }
        for( int i = 0 ; i < 32; i ++ ) 
            cout<< a[i] << " "; 
        cout<< "\n";
        for(int i =0 ;i < 32; i ++ ) 
            a[i] = a[i] % 3;
        int ans = 0 ; 
        for( int i =0; i < 32; i++){
            ans = ans + pow(2,i) * a[i]; 
        }
        return ans;
    }
};