class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two substrings
     */
    int maxDiffSubArrays(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int leftmax[n]; 
        int rightmax[n]; 
        int leftmin[n]; 
        int rightmin[n];
        int sum =0; 
        int maxyet = INT_MIN;
        for( int i= 0 ; i < nums.size(); i++ ) {
            sum = sum + nums[i]; 
            if( sum > maxyet) 
                maxyet = sum ; 
            if( sum < 0 ) 
                sum = 0;
            leftmax[i] = maxyet;
        }
        maxyet = INT_MIN; 
        sum =0;
        for( int i = n-1 ; i >=0;i--){
            sum = sum + nums[i];
            if( sum >= maxyet) 
                maxyet = sum ; 
            if( sum <0) 
                sum =0; 
            rightmax[i] = maxyet;
        }
        int minyet = INT_MAX;
        sum = 0 ; 
        for( int i = 0 ;i< n;i++ ) {
            if( sum > 0) 
                sum = nums[i];
            else
                sum += nums[i];
            if( sum < minyet ) 
                minyet = sum;
            leftmin[i] = minyet;
        }
        minyet = INT_MAX;
        sum = 0 ; 
        for( int i =n -1; i >= 0 ; i--){
            if(sum > 0) 
                sum = nums[i];
            else 
                sum += nums[i];
            if( sum < minyet ) 
                minyet = sum ; 
            rightmin[i] = minyet; 
        }
        int ans = 0 ;
        for( int i = 0 ; i < n-1;i++ ) {
            ans = max(ans,abs(leftmax[i] - rightmin[i+1]));
            ans = max( ans, abs(leftmin[i] - rightmax[i+1]));
        }
        return ans;
    }
};