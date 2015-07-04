public class Solution {
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    public int kSum(int A[], int k, int target) {
        // write your code here
        int len = A.length;
        int [][][]dp = new int[len + 1][k + 1][target + 1];
        dp[0][0][0] = 1;
        for (int i = 0; i < len; i ++) {
            for (int j = 0; j <= k && j <= i; j ++) {
                for (int v = 0; v <= target; v ++) {
                    if (v + A[i] <= target  && j < k) dp[i + 1][j + 1][v + A[i]] += dp[i][j][v];
                    dp[i + 1][j][v] += dp[i][j][v];
                }
            }
        }
        return dp[len][k][target];
    }
}

