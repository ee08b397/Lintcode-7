public class Solution {
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    public int dfs(int[][] A, int [][]dp, int x, int y) {
        if (dp[x][y] != -1) return dp[x][y];
        int temp = 1;
        if (x - 1 >= 0 && A[x][y] > A[x - 1][y]) {
            temp = Math.max(temp, dfs(A, dp, x - 1, y) + 1);
        }
        if (x + 1 < A.length && A[x][y] > A[x + 1][y]) {
            temp = Math.max(temp, dfs(A, dp, x + 1, y) + 1);
        }
        if (y - 1 >= 0 && A[x][y] > A[x][y - 1]) {
            temp = Math.max(temp, dfs(A, dp, x, y - 1) + 1);
        }
        if (y + 1 < A[0].length && A[x][y] > A[x][y + 1]) {
            temp = Math.max(temp, dfs(A, dp, x, y + 1) + 1);
        }
        if (temp == -1) return dp[x][y] = 1;
        else return dp[x][y] = temp;
    }
    public int longestIncreasingContinuousSubsequenceII(int[][] A) {
        // Write your code here
        if (A == null || A.length == 0 || A[0].length == 0) return 0;
        int lenx = A.length, leny = A[0].length;
        int [][] dp = new int[lenx][leny];
        for (int i = 0; i < lenx; i ++) {
            for (int j = 0; j < leny; j ++) {
                dp[i][j] = -1;
            }
        }
        int maxlen = 0;
        for (int i = 0; i < lenx; i ++) {
            for (int j = 0; j < leny; j ++) {
                maxlen = Math.max(maxlen, dfs(A, dp, i, j));
            }
        }
        return maxlen;
    }
}