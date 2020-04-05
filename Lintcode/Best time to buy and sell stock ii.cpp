class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        //all we need is the consecutive peak and valleys
        int ans = 0; 
        int n = prices.size();
        for(int i= 1 ; i < n;i++ ) {
            if( prices[i] > prices[i-1])
                ans += prices[i] - prices[i-1];
        }
        return ans;
    }
};