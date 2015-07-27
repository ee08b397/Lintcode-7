#include <vector>

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector <int> > ivec(m ,vector<int>(n));
        if (obstacleGrid[0][0] == 1) return 0;
        ivec[0][0] = 1;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (obstacleGrid[i][j] == 1) ivec[i][j] = 0;
                else if (i != 0 || j != 0) {
                    if (i == 0) ivec[i][j] = ivec[i][j-1];
                    else if (j == 0) ivec[i][j] = ivec[i-1][j];
                    else ivec[i][j] = ivec[i-1][j] + ivec[i][j-1];
                }
            }
        }
        return ivec[m-1][n-1];
    }
};
