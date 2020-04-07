class Solution {
public:
    /*
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        map<int,int> mp ; // for first
        for(int i = 0  ;i < n;i++ ) {
            mp[A[i]]++ ; 
        }
        map<int,int,greater<int> > revmp;
        for( auto i : mp){
            revmp[i.second] = i.first;
        }
        int w = 0 ; 
        int ans = INT_MAX;
        int newans= 0 ; 
        int flag = true;
        for( auto i : revmp){
            flag = true;
            newans= 0 ; 
            w = 0;
            for( int j = 0 ;j < n;j ++ ) {
                if( A[j] == i.second){
                    w++;
                }
                else{
                    if( B[j] == i.second){
                        newans++ ; 
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
            }
            if( flag && w + newans == n)
                ans = min(newans ,ans) ;
        }
        //int n = A.size();
        //map<int,int> mp ; // for second
        mp.clear();
        for(int i = 0  ;i < n;i++ ) {
            mp[B[i]]++ ; 
        }
        //map<int,int> revmp;
        for( auto i : mp){
            revmp[i.second] = i.first;
        }
        w = 0 ; 
        //int ans = INT_MAX;
        newans= 0 ; 
        flag = true;
        for( auto i : revmp){
            flag = true;
            w = 0 ; 
            newans =0 ; 
            for( int j = 0 ;j < n;j ++ ) {
                if( B[j] == i.second){
                    w++;
                }
                else{
                    if( A[j] == i.second){
                        newans++ ; 
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
            }
            if( flag && w + newans == n)
                ans = min(newans ,ans) ;
        }
        if( ans == INT_MAX)
            return -1;
        return ans;
    }
    */
    int minDominoRotations(vector<int>& A, vector<int>& B){
        int n= A.size(); 
        int countA[6] = {0};
        int countB[6] = {0};
        int same[6] = {0};
        for( int i = 0 ; i< n ;i++ ){
                countA[A[i]-1]++;
                countB[B[i]-1]++;
            if( A[i] == B[i])
                same[A[i]-1]++;
        }
        bool flag = false;
        int ans = INT_MAX;
        for( int i = 0 ; i<6;i++ ) {
            if( countA[i] + countB[i] - same[i] == n){
                flag = true;
                ans = min(ans,n - max(countA[i] , countB[i])); 
            }
        }
        if(flag)
            return ans;
        return -1;
    }
    
};