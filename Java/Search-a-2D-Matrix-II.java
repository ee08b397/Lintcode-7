public class Solution {
    /**
     * @param matrix: A list of lists of integers
     * @param: A number you want to search in the matrix
     * @return: An integer indicate the occurrence of target in the given matrix
     */
    public int searchMatrix(int[][] matrix, int target) {
        // write your code here
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;
        int cur = 0, x = 0, y = matrix[0].length - 1;
        while (x < matrix.length && y >= 0) {
            if (matrix[x][y] == target) {
                cur ++;
                x ++;
            } else if (matrix[x][y] < target) {
                x ++;
            } else {
                y --;
            }
        }
        return cur;
    }
}
