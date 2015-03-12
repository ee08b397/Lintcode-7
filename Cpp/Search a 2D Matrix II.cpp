class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1, cnt = 0;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                cnt ++;
                y --;
                x ++;
            } else if(matrix[x][y] > target) {
                y --;
            } else x ++;
        }
        return cnt;
    }
};
