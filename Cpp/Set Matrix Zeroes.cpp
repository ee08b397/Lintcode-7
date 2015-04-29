#include <vector>

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        if (matrix.empty()) return;
        int len1 = matrix.size(), len2 = matrix[0].size();
        int x = 1, y = 1;
        for (int i = 0; i < len2; i ++) {
            if (matrix[0][i] == 0) {
                x = 0;
            }
        }
        for (int i = 0; i < len1; i ++) {
            if (matrix[i][0] == 0) {
                y = 0;
            }
        }
        for (int i = 1; i < len1; i ++) {
            for (int j = 1; j < len2; j ++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < len1; i ++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < len2; j ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < len2; i ++) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < len1; j ++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (x == 0) {
            for (int i = 0; i < len2; i ++) matrix[0][i] = 0;
        }
        if (y == 0) {
            for (int i = 0; i < len1; i ++) matrix[i][0] = 0;
        }
    }
};
