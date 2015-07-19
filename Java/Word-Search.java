public class Solution {
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    public boolean helper(char[][] board, int[][] vis, String word, int pos, int x, int y) {
        if (pos == word.length()) return true;
        for (int i = 0; i < 4; i ++) {
            int x1 = x + dx[i], y1 = y + dy[i];
            if (x1 >= 0 && x1 < board.length && y1 >= 0 && y1 < board[0].length &&
                    board[x1][y1] == word.charAt(pos) && vis[x1][y1] == 0) {
                vis[x1][y1] = 1;
                if(helper(board, vis, word, pos + 1, x1, y1)) return true;
                vis[x1][y1] = 0;
            }
        }
        return false;
    }
    public boolean exist(char[][] board, String word) {
        // write your code here
        if (board == null || board.length == 0 || board[0].length == 0 || word.length() == 0) return false;
        int lenx = board.length, leny = board[0].length;
        int[][] vis = new int[lenx][leny];
        for (int i = 0; i < lenx; i ++) {
            for (int j = 0; j < leny; j ++) {
                if (board[i][j] == word.charAt(0)) {
                    vis[i][j] = 1;
                    if (helper(board, vis, word, 1, i, j)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
}