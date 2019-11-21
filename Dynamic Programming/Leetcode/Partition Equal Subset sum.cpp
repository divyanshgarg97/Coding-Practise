class Solution {
public:
    /*approach1: backtracking(TLE)
    bool go(vector<int> &nums, int target,int index){
        if( index >=nums.size()) //reached the end  
            return false;
        if( target < nums[index]) return false; //target has already been less than nums[index ] means extra values added
        if( target == nums[index]) return true; 
        return go( nums , target - nums[index] , index+1) || go(nums, target , index+1); 
        
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ; 
        if( n == 0 ) 
            return true; 
        int sum= 0 ; 
        for( int i = 0; i < n;i++) 
            sum +=nums[i];
        if( sum%2 == 1)
            return false; 
        int target = sum / 2; 
        int index = 0 ; 
        return go(nums,target, index); 
    }
    */
    //approach2: simple 0/1 knapsack logic
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ; 
        if( n == 0 ) 
            return true; 
        int sum= 0 ; 
        for( int i = 0; i < n;i++) 
            sum +=nums[i];
        if( sum%2 == 1)
            return false; 
        int target = sum / 2; 
        int index = 0 ; 
        bool dp[n+1][target +1 ];
        for( int i = 0 ;i < n+1; i++ ) 
            dp[i][0]= true; 
        for( int i = 0 ; i < target + 1; i ++ ) 
            dp[0][i] = false; 
        for( int i = 1; i < n+ 1 ; i++ ){
            for( int j = 1; j < target + 1; j ++ ) {
                dp[i][j] = dp[i-1][j];
                if( j >= nums[i-1])
                    dp[i][j] = (dp[i][j] || dp[i - 1][j - nums[i-1]]);
            }
        }
        return dp[n][target];
    }
    
    
    
};