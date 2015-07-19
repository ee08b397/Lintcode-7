class Solution {
    /**
     * @param board: the board
     * @return: wether the Sudoku is valid
     */
    public boolean isValidSudoku(char[][] board) {
        int[][] row = new int[9][9];
        int[][] col = new int[9][9];
        int[][] mat = new int[9][9];
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    int temp = board[i][j] - '1';
                    row[i][temp] ++;
                    col[j][temp] ++;
                    int x = i / 3, y = j / 3;
                    mat[x * 3 + y][temp] ++;
                }
            }
        }
        for (int i = 0; i < 9; i ++) {
            for(int j = 0; j < 9; j ++) {
                if (mat[i][j] > 1 || col[i][j] > 1 || row[i][j] > 1) return false;
            }
        }
        return true;
    }
};
