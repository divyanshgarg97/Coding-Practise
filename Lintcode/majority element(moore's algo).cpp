class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
        
        // write your code here
        // Use the moore algorithm 
        // step1: find the possible candidate and count 
        //              if( a[i] == candidate) 
        //                    count ++;
        //                else 
        //                   count --;
        int n = nums.size();
        int count = 0 ; 
        int candidate; 
        for( int i = 0 ; i < n ;i++ ) {
            if( count == 0) {
                candidate = nums[i];
                count ++ ;
            }
            else{
                if (nums[i] == candidate)
                    count++;
                else 
                    count--;
            }
        }
        return candidate;
        //above worked because we were given ,we will always have majority element
        // if not then we need to check as it might be possible that candidate is not always the majority element
        //eg:-[2,1,2,4,7]
        //candidate will be 7 , with count = 1 ,so we need one more loop to check if 7 exists more than n/2 or not
    }
};