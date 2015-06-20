class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m * n - 1, mid;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            int cur = matrix[mid / n][mid % n];
            if (cur == target) return true;
            else if (cur > target) end = mid;
            else start = mid;
        }
        if (matrix[start / n][start % n] == target) return true;
        else if (matrix[end / n][end % n] == target) return true;
        return false;
    }
};
