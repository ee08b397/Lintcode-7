public class Solution {
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        // write your code here
        int m = obstacleGrid.length;
        if (m == 0) return 0;
        int n = obstacleGrid[0].length;
        if (obstacleGrid[0][0]) return 0;
        int [ ][ ]dp = new int[m][n];
        dp[0][0] = 1;
        for (int i = 1; i < n; i ++) {
        	if (obstacleGrid[0][i] == 0) dp[0][i] = dp[0][i - 1];
        	else dp[0][i] = 0;
        }
        for (int i = 1; i < m; i ++) {
        	if (obstacleGrid[i][0] == 0) dp[i][0] = dp[i - 1][0];
        	else dp[i][0] = 0;
        }
        for (int i = 1; i < m; i ++) {
        	for (int j = 1; j < n; j ++) {
        		if (obstacleGrid[i][j] == 0) {
        			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        		} else {
        			dp[i][j] = 0;
        		}
        	}
        }
        return dp[m - 1][n - 1];
    }
}
