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
    void dfs(vector<vector<string> > &vec, vector<vector<int> > &vis, vector<string> &st, int pos, int n) {
        if (pos == n) {
            vec.push_back(st);
            return;
        }
        for (int i = 0; i < n; i ++) {
            if (vis[0][i] == 0 && vis[1][i+pos] == 0 && vis[2][n-i+pos] == 0) {
                vis[0][i] = vis[1][i+pos] = vis[2][n-i+pos] = 1;
                st[pos][i] = 'Q';
                dfs(vec, vis, st, pos + 1, n);
                st[pos][i] = '.';
                vis[0][i] = vis[1][i+pos] = vis[2][n-i+pos] = 0;
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        //if (n <= 1) return n;
        vector<vector<string> > vec;
        vector<string> st(n, string(n, '.'));
        vector<vector<int> > vis(3, vector<int>(30));
        dfs(vec, vis, st, 0, n);
        return vec;
    }
};

