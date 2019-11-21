class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //dp with O(n) time and O(n) space
        //can take just variables up and down also , rather than taking array to reduce space complexity.
        int n = nums.size() ; 
        if( n == 0 || n == 1) 
            return n; 
        int up[n]; //ending with positive difference among last two values, basically increasing.
        int down[n];//ending with negative differenve among last two values , basically decreasing.
        up[0]=1;
        down[0]=1;
        for( int i = 1; i < n;i++ ) {
            if( nums[i] > nums[i-1]){
                up[i]  =down[i-1] +1;
                down[i] = down[i-1];
            }
            else if( nums[i] < nums[i-1]){
                down[i] = up[i-1]+1;
                up[i] = up[i-1];
            }
            else {
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        return max(up[n-1], down[n-1]);
    }
    
};