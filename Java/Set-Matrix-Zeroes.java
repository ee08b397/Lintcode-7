public class Solution {
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    public void setZeroes(int[][] matrix) {
        // write your code here
        if (matrix == null || matrix.length <= 0) return;
        int lenx = matrix.length, leny = matrix[0].length;
        int sign1 = 1, sign2 = 1;
        for (int i = 0; i < leny; i ++) {
            if (matrix[0][i] == 0) {
                sign1 = 0;
                break;
            }
        }
        for (int i = 0; i < lenx; i ++) {
            if (matrix[i][0] == 0) {
                sign2 = 0;
                break;
            }
        }
        for (int i = 0; i < lenx; i ++) {
            for (int j = 0; j < leny; j ++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < lenx; i ++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < leny; j ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < leny; i ++) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < lenx; j ++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (sign1 == 0) {
            for (int i = 0; i < leny; i ++) {
                matrix[0][i] = 0;
            }
        }
        if (sign2 == 0) {
            for (int i = 0; i < lenx; i ++) {
                matrix[i][0] = 0;
            }
        }
    }
}