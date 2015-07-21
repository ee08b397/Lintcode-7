class Solution {
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    public int maxProfit(int[] prices) {
        // write your code here
        if (prices == null || prices.length <= 1) return 0;
        int cur = prices[0], len = prices.length;
        int[] leftmax = new int[len];
        for (int i = 1; i < len; i ++) {
            leftmax[i] = Math.max(leftmax[i - 1], prices[i] - cur);
            cur = Math.min(cur, prices[i]);
        }
        int[] rightmax = new int[len];
        cur = prices[len - 1];
        for (int i = len - 2; i >= 0; i --) {
            rightmax[i] = Math.max(rightmax[i + 1], cur - prices[i]);
            cur = Math.max(cur, prices[i]);
        }
        int maxp = 0;
        for (int i = 0; i < len; i ++) {
            maxp = Math.max(maxp, leftmax[i] + rightmax[i]);
        }
        return maxp;
    }
};