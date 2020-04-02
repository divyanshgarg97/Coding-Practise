
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size() ; 
        if( n == 0) return 0;
        bool dp[n][n] = {false};
        //considering all first for length 3
        int count = 0  ;
        for( int i = 0 ;i < n - 2 ;i++ ) {
            if( A[i+1] - A[i] == A[i+2] - A[i+1]){
                dp[i][i + 2] = true;
                count++; 
            }
        }
        //dp of i , j means that including i and j both and all in between can form a arithmetic slice or not
        for( int k =4 ;k <=n; k ++ ) {
            for( int i = 0 ;i< n - k + 1 ;i ++ ) {
                int j = i + k -1 ; 
                if( dp[i+1][j] == true && A[i+2] - A[i+1] == A[i+1] - A[i]){
                    //that means i can also be included in Arithmetic slices
                    dp[i][j] = true;
                    count++;
                }
                else if( dp[i][j-1]== true && A[j-2] - A[j-1] == A[j-1] - A[j]){
                    //that means jth element can also be included in Arithmetic slice
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
        
    }
};