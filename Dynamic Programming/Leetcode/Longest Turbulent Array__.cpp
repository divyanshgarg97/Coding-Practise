class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n = nums.size() ; 
        if( n== 0 || n == 1) 
            return n; 
        vector<int> up(n, 1 ) ; //  up[n] 
        vector<int> down(n , 1) ;//  down[n];
        up[0] = 1; 
        down[0] = 1;
        int ans = 1; 
        for( int i = 1;i < n;i++ ){
            if( nums[i] > nums[i-1]){
                up[i] = down[i-1] + 1;
                ans = max( ans, up[i]);
                //down[i] = down[i-1];//cannot add this as subarray not subsequence
            }
            else if( nums[i] < nums[i-1]){
                down[i] = up[i-1] + 1;
                ans = max( down[i] , ans);
                //up[i] = up[i-1];//cannot add this as subarray not subsequence
            }
            else{
                up[i] = 1;
                down[i]=1;
            }
        }
        return ans;
    }
};