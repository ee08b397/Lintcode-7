class Solution {
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    public int maxProfit(int[] prices) {
        // write your code here
        int res = 0, cur = Integer.MAX_VALUE;
        for (int i = 0; i < prices.length; i ++) {
            if (prices[i] >= cur) {
                res = res + (prices[i] - cur);
            }
            cur = prices[i];
        }
        return res;
    }
};