public class Solution {
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    public int maxSquare(int[][] matrix) {
        // write your code here
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;
        int maxsq = 0;
        int lenx = matrix.length, leny = matrix[0].length;
        int [][] vis = new int[lenx][leny];
        for (int i = 0; i < lenx; i ++) {
            if (matrix[i][0] == 1) {
                vis[i][0] = 1;
                maxsq = Math.max(maxsq, 1);
            }
        }
        for (int i = 0; i < leny; i ++) {
            if (matrix[0][i] == 1) {
                vis[0][i] = 1;
                maxsq = Math.max(maxsq, 1);
            }
        }
        for (int i = 1; i < lenx; i ++) {
            for (int j = 1; j < leny; j ++) {
                if (matrix[i][j] == 1) {
                    vis[i][j] = Math.min(vis[i - 1][j - 1], Math.min(vis[i - 1][j], vis[i][j - 1])) + 1;
                    maxsq = Math.max(maxsq, vis[i][j]);
                }
            }
        }
        return maxsq * maxsq;
    }
}
