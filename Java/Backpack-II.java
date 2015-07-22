public class Solution {
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    public int backPackII(int m, int[] A, int V[]) {
        // write your code here
        int n = A.length, maxP = Integer.MIN_VALUE;
        int[][] dp = new int[n + 1][m + 1];
        for (int[] row: dp)
            Arrays.fill(row, -1);
        dp[0][0] = 0;
        for (int i = 0; i < n; i ++) {
            for(int j = 0; j <= m; j ++) {
                if (dp[i][j] != -1) {
                    if (j + A[i] <= m) {
                        dp[i + 1][j + A[i]] = Math.max(dp[i + 1][j + A[i]], dp[i][j] + V[i]);
                        maxP = Math.max(maxP, dp[i + 1][j + A[i]]);
                    }
                    dp[i + 1][j] = Math.max(dp[i][j], dp[i + 1][j]);
                    maxP = Math.max(maxP, dp[i + 1][j]);
                }
            }
        }
        return maxP;
    }
}