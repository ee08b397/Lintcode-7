public class Solution {
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    public void rotate(int[][] matrix) {
        // write your code here
        if (matrix == null || matrix.length <= 1) return;
        int len = matrix.length;
        for (int i = 0; i < len / 2; i ++) {
            for (int j = 0; j < len; j ++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[len - i - 1][j];
                matrix[len - i - 1][j] = temp;
            }
        }
        for (int i = 0; i < len; i ++) {
            for (int j = i + 1; j < len; j ++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}