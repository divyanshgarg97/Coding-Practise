class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        for( int i = 0 ; i < n;i++) {
            if( A[i][0] == 0) {
                // toggle complete row
                for( int j = 0 ;j < m;j ++ ) {
                    if( A[i][j] ==0)
                        A[i][j] =1;
                    else
                        A[i][j] =0;
                }
            }
        }
        int count = 0; 
        for( int i = 0 ; i < m;i++ ) {
            for(int j = 0 ;j < n; j++ ) {
                if( A[j][i] == 0){
                    count ++ ; 
                }
            }
            if( count  > n / 2 ) { //toggle complete column
                for( int j= 0 ;j < n;j ++ ) {
                    if( A[j][i] ==0)
                        A[j][i] =1;
                    else
                        A[j][i] =0;
                }
            }
            count = 0 ; 
        }
        for( int i = 0 ; i < n;i++){
            for(int j = 0;j< m ;j++ ) 
                    cout<< A[i][j]<< " ";
            cout<< "\n";
        }
        int ans = 0;
        for( int i = 0 ; i < n ;i++ ) {
            for( int j = 0 ;j < m ;j ++ ) {
                ans = ans + (A[i][j] <<( m - j - 1));
            }
        }
        return (int)ans;
    }
};