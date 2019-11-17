class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ; 
        if(n== 0 ) return 0 ; 
        if (n==1 ) return nums[0];
        if( n== 2 ) return max( nums[0], nums[1]);
        if( n== 3 ) return max( max(nums[0], nums[2] ), nums[1]);
        int dp1[n-1];
        //if take first element then 0 to n-2;
        dp1[0] = nums[0];
        dp1[1] = max(nums[1] , dp1[0]);
        for( int i = 2; i< n-1; i ++ ) {
            dp1[i] = max( dp1[i-1] , nums[i] + dp1[i-2]);
        }
        //if does not take first element then 1 to n-1 and take the last element
        //just reverse
        reverse(nums.begin() , nums.end()); 
        int dp2[n-1];
        dp2[0] = nums[0];
        dp2[1] = max(nums[1] , dp2[0]);
        for( int i = 2; i< n-1; i ++ ) {
            dp2[i] = max( dp2[i-1] , nums[i] + dp2[i-2]);
        }
        return max( dp1[n-2], dp2[n-2]);
    }
};