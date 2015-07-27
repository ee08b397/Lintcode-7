#include <vector>

class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int dfs(vector<vector<int> > &A, vector<vector<int> > &dp, int x, int y, const int &lenx, const int &leny) {
        if (dp[x][y] != -1) return dp[x][y];
        int temp = -1;
        if (x - 1 >= 0 && A[x][y] > A[x-1][y]) {
            temp = max(temp, dfs(A, dp, x - 1, y, lenx, leny) + 1);
        }
        if (x + 1 < lenx && A[x][y] > A[x+1][y]) {
            temp = max(temp, dfs(A, dp, x + 1, y, lenx, leny) + 1);
        }
        if (y - 1 >= 0 && A[x][y] > A[x][y-1]) {
            temp = max(temp, dfs(A, dp, x, y - 1, lenx, leny) + 1);
        }
        if (y + 1 < leny && A[x][y] > A[x][y+1]) {
            temp = max(temp, dfs(A, dp, x, y + 1, lenx, leny) + 1);
        }
        if (temp == -1) return dp[x][y] = 1;
        else return dp[x][y] = temp;
    }
    int longestIncreasingContinuousSubsequenceII(vector<vector<int> >& A) {
        // Write your code here
        if (A.empty() || A[0].empty()) return 0;
        int lenx = A.size(), leny = A[0].size(), maxlen = 1;
        vector<vector<int> > IncreSubLength(lenx, vector<int> (leny, -1));
        //int maxlen = 1;
        for (int i = 0; i < lenx; i ++) {
            for (int j = 0; j < leny; j ++) {
                maxlen = max(maxlen, dfs(A, IncreSubLength, i, j, lenx, leny));
            }
        }
        return maxlen;
    }
};
