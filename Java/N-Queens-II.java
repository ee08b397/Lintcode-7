class Solution {
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    private int num;
    public void helper( int[][] vis, int pos, int n) {
        if (pos == n) {
            num++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (vis[0][i] == 0 && vis[1][pos + i] == 0 && vis[2][n - i + pos] == 0) {
                vis[0][i] = vis[1][pos + i] = vis[2][n - i + pos] = 1;
                helper(vis, pos + 1, n);
                vis[0][i] = vis[1][pos + i] = vis[2][n - i + pos] = 0;
            }
        }
    }
    public int totalNQueens(int n) {
        //write your code here
        num = 0;
        if (n == 0) return 0;
        int[][] vis = new int[3][30];
        helper(vis, 0, n);
        return num;
    }
};