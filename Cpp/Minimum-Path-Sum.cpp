class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int m = grid.size(), n = grid[0].size();
        vector<vector <int> > ivec(m ,vector<int>(n));
        ivec[0][0] = grid[0][0];
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != 0 || j != 0) {
                    if (i == 0) ivec[i][j] = ivec[i][j-1] + grid[i][j];
                    else if(j == 0) ivec[i][j] = ivec[i-1][j] + grid[i][j];
                    else ivec[i][j] = min(ivec[i-1][j], ivec[i][j-1]) + grid[i][j];
                }
            }
        }
        return ivec[m-1][n-1];
    }
};
