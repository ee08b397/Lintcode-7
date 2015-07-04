public class Solution {
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    public int MinAdjustmentCost(ArrayList<Integer> A, int target) {
        // write your code here
        int len = A.size();
        if (len <= 1) return 0;
        int [][]dp = new int[len][105];
        for (int i = 0; i < len; i ++) {
            for (int j = 1; j <= 100; j ++) {
                if (i == 0) {
                    dp[i][j] = Math.abs(j - A.get(i));
                } else {
                    dp[i][j] = Integer.MAX_VALUE;
                    for (int k = 1; k <= 100; k ++) {
                        if (Math.abs(k - j) > target) continue;
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + Math.abs(j - A.get(i)));
                    }
                }
            }
        }
        int minv = Integer.MAX_VALUE;
        for (int i = 1; i <= 100; i ++) {
            minv = Math.min(minv, dp[len - 1][i]);
        }
        return minv;
    }
}
