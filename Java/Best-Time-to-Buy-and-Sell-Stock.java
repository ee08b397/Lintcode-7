public class Solution {
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    public int maxProfit(int[] prices) {
        // write your code here
        int maxP = 0, minPrice = Integer.MAX_VALUE;
        for (int i = 0; i < prices.length; i ++) {
            maxP = Math.max(maxP, prices[i] - minPrice);
            minPrice = Math.min(minPrice, prices[i]);
        }
        return maxP;
    }
}
