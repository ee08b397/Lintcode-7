#include <vector>
#include <string>

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool solve(vector<vector<char> > &board, string &word, int pos, int x, int y, vector<vector<int> > &vis) {
        if (pos >= word.size()) return true;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i ++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (x1 >= 0 && x1 < board.size() && y1 >= 0 && y1 < board[0].size() && board[x1][y1] == word[pos] && vis[x1][y1] == 0) {
                vis[x1][y1] = 1;
                if (solve(board, word, pos + 1, x1, y1, vis)) return true;
                vis[x1][y1] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        int len1 = board.size(), len2 = board[0].size();
        vector<vector<int> > vis(len1, vector<int> (len2));
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = 1;
                    if (solve(board, word, 1, i, j, vis)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};
