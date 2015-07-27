#include <vector>
#include <string>

class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    void dfs(int &res, vector<vector<int> > &vis, int pos, int n) {
        if (pos == n) {
            res ++;
            return;
        }
        for (int i = 0; i < n; i ++) {
            if (vis[0][i] == 0 && vis[1][i+pos] == 0 && vis[2][n-i+pos] == 0) {
                vis[0][i] = vis[1][i+pos] = vis[2][n-i+pos] = 1;
                dfs(res, vis, pos + 1, n);
                vis[0][i] = vis[1][i+pos] = vis[2][n-i+pos] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        // write your code here
        vector<vector<int> > vis(3, vector<int>(30));
        int res = 0;
        dfs(res, vis, 0, n);
        return res;
    }
};

