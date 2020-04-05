class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    /*
    //Sum all of them
    int findMissing(vector<int> &nums) {
        // write your code here
        int n = nums.size(), sum = 0;
        for( int i = 0 ;i < n;i++) 
            sum +=nums[i];
        return (n*(n + 1) / 2)  - sum;
    }*/
    //to avoid overflow
    /*
    int findMissing(vector<int> &nums){
        int n = nums.size(); 
        int d = n ; // not started with 0 , as might lead to negative overflow
        for( int i =0 ; i <n;i++ ) 
            d = d + i - nums[i];
        return d;
    }*/
    //XOR 
    int findMissing(vector<int> &nums){
        int n = nums.size();
        int x = 0; 
        for( int i = 0 ;i < n; i++ ) {
            x = x ^ i  ^ nums[i];
        }
        x = x ^ n; 
        return x;
    }
};