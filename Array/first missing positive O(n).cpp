class Solution {
public:
    /*void swap( int & a , int &b) {
        a= a+ b;
        b = a - b; 
        a = a - b; 
    }*/
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size() ; 
        //although two loops but still O(n) only
        for( int i = 0 ;i< n;i++ ) {
            //using while is very important as value came after swapping can be incorrect for that position
            while( nums[i] >0 && nums[i] <n && nums[i]!= nums[nums[i] -1] ){
                swap(nums[nums[i] -1 ] , nums[i]);
                //need to swap only as overriding nums[nums[i] -1 ] to nums[i] will delete override value stored at nums[nums[i] -1 ] initialy
            }
        }
        for( int i = 0 ;i< n;i++) {
            cout<< nums[i]<<" ";
        }
        for( int i =0 ;i< n;i++ ) {
            if( nums[i]!=i + 1) 
                return i + 1; 
        }
        return n+1; 
    }
    
};