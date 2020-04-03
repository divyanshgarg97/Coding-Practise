class Solution {
public:
    /*
    int maxSubArray(vector<int>& nums) {
        // prefix sum store ,than check for every i to j index using sum = pre[j] - pre[i-1] O(n^2)
        //kadane's algo O(n)
        int n = nums.size();
        int max_till_now = INT_MIN ; 
        int current_sum= 0 ; 
        for( int i = 0 ; i <n ;i++ ) {
            current_sum = current_sum + nums[i] ; 
            if( max_till_now < current_sum)
                max_till_now = current_sum;
            if( current_sum < 0 ) 
                current_sum = 0 ; 
        }
        return max_till_now;
        
    }
    */ 
    // divide and conquer,divide in half , find left max , find right max and find between left and right max i.e. when we expand around the mid element
    int expandaroundmid(vector<int> nums, int l , int m , int r ) {
        int left_sum = INT_MIN;
        int sum = 0 ; 
        for( int i = m ; i >= l; i--) {
            sum+= nums[i];
            if( sum > left_sum ) 
                left_sum = sum;
        }
        int right_sum = INT_MIN;
        sum = 0; 
        for(int i = m+1; i <= r; i ++ ) {
            sum += nums[i];
            if( sum > right_sum)
                right_sum = sum;
        }
        return left_sum + right_sum;
    }
    int divideandconquer(vector<int> nums, int l , int r ) {
        if( l == r ) 
            return nums[l]; 
        int m = (r+l)/2;
        return max(max(divideandconquer(nums,l,m), divideandconquer(nums,m+1,r)), expandaroundmid(nums,l,m,r));
    }
    int maxSubArray(vector<int>& nums){
        return divideandconquer(nums,0,nums.size()-1) ;
    
    }
};