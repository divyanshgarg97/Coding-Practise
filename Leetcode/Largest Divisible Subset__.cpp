class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //O(n2) time and O(n) space
        int n = nums.size() ; 
        if( n== 0 ) 
            return {}; 
        if(n == 1 ) 
            return {nums[0]};
        vector<int > prev(n , -1);
        vector<int> dp (n , 1 ) ;
        sort(nums.begin() , nums.end()) ;
        int start = 0 ; 
        int max = 1; 
        for( int i = 1; i < n ;i++){
            for( int j = 0 ;j < i ;j++ ) {
                if( nums[j] % nums[i] ==0 || nums[i] % nums[j]==0){
                    if( dp[j] + 1  > dp[i]){
                        dp[i] = dp[j] + 1;  
                        prev[i] = j ;
                        if( dp[i] >=max){//basically so that we can traverse back to get the solution
                            max = dp[i];//max will be the size of allocate
                            start = i ; 
                        }
                    }
                }
            }
        }
        // good way
        int i = max -1 ;
        vector<int> ans (max , 0) ; 
        while(start!=-1){//as -1 will be the prev of first
            ans[i] = nums[start];
            start = prev[start];
            i--;
        }
        return ans;
    }
};