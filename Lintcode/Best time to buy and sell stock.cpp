class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        // write your code here
        // for every i ,check with the minimum value encountered so far;
        int n = prices.size();
        if( n ==0) return 0 ; 
        int min_sofar = prices[0];
        int ans = INT_MIN;
        for( int i = 0 ; i< n ;i++ ) {
            if( prices[i] - min_sofar > ans){
                ans = prices[i] - min_sofar;
            }
            if( prices[i] < min_sofar)
                min_sofar = prices[i]; 
        }
        return ans;
    }
};