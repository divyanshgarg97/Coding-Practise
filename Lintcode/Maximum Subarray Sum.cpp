class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        //kadane's algorithm
        int sum_so_far = 0 ; 
        int max_so_far = nums[0] ;
        for( int i = 0 ; i < nums.size(); i++ ) {
            sum_so_far += nums[i]; 
            if( max_so_far < sum_so_far)
                max_so_far = sum_so_far;
            if( sum_so_far < 0 )
                sum_so_far = 0 ; 
        }
        return max_so_far;
    }
};