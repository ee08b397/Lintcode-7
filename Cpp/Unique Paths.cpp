class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector<vector <int> > ivec(m ,vector<int>(n));
        ivec[0][0] = 1;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != 0 || j != 0) {
                    if (i == 0) ivec[i][j] = ivec[i][j-1];
                    else if (j == 0) ivec[i][j] = ivec[i-1][j];
                    else ivec[i][j] = ivec[i-1][j] + ivec[i][j-1];
                }
            }
        }
        return ivec[m-1][n-1];
    }
};
