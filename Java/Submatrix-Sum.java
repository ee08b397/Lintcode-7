public class Solution {
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    public int[][] submatrixSum(int[][] matrix) {
        // Write your code here
        int[][] result = new int[2][2];
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return result;
        int lenx = matrix.length, leny = matrix[0].length;
        int[][][] mat = new int[leny][lenx][lenx];
        for (int i = 0; i < leny; i ++) {
            int[] sum = new int[lenx];
            sum[0] = matrix[0][i];
            for (int j = 1; j < lenx; j ++) {
                sum[j] = sum[j - 1] + matrix[j][i];
            }
            for (int j = 0; j < lenx; j ++) {
                for (int k = j; k < lenx; k ++) {
                    mat[i][j][k] = sum[k] - sum[j] + matrix[j][i];
                }
            }
        }
        for (int i = 0; i < lenx; i ++) {
            for (int j = 0; j < lenx; j ++) {
                HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
                hash.put(0, -1);
                int cur = 0;
                for (int k = 0; k < leny; k ++) {
                    cur += mat[k][i][j];
                    if (hash.containsKey(cur)) {
                        result[0][0] = i;
                        result[0][1] = hash.get(cur) + 1;
                        result[1][0] = j;
                        result[1][1] = k;
                        return result;
                    } else {
                        hash.put(cur, k);
                    }
                }
            }
        }
        return result;
    }
}
