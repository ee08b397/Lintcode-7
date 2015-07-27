class Solution {
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    public int helper(int[] prices) {
        int res = 0;
        for (int i = 1; i < prices.length; i ++) {
            if (prices[i] > prices[i - 1]) res += (prices[i] - prices[i - 1]);
        }
        return res;
    }
    public int maxProfit(int k, int[] prices) {
        // write your code here
        if (k == 0) return 0;
        if (k >= prices.length) {
            return helper(prices);
        }
        int n = prices.length;
        int[][] mustsell = new int[n + 1][n + 1];   // mustSell[i][j] 表示前i天，至多进行j次交易，第i天必须sell的最大获益
        int[][] globalbest = new int[n + 1][n + 1];  // globalbest[i][j] 表示前i天，至多进行j次交易，第i天可以不sell的最大获益
        for (int i = 1; i < n; i ++) {
            int profit = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; j ++) {
                mustsell[i][j] = Math.max(globalbest[i - 1][j - 1] + profit,
                        mustsell[i - 1][j] + profit);
                globalbest[i][j] = Math.max(globalbest[i - 1][j], mustsell[i][j]);
            }
        }
        return globalbest[n - 1][k];
    }
};