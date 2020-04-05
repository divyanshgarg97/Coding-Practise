class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(); 
        // two pointers // zeroptr for zero tracker and curr for in general movement
        int zeroptr  = -1; 
        for( int curr = 0 ; curr < n ;curr++){
            if( nums[curr]==0){
                if( zeroptr == -1)
                    zeroptr = curr;
            }
            else{
                if( zeroptr != -1 && zeroptr < n ) {
                    swap(nums[curr] ,nums[zeroptr]);
                    zeroptr++;
                }
            }
        }
        //return nums;  
    }
};