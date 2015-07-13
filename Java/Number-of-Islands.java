public class Solution {
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    public void dfs(boolean[][] grid, int x, int y) {
        grid[x][y] = false;
        for (int i = 0; i < 4; i ++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (x1 >= 0 && x1 < grid.length && y1 >= 0 && y1 < grid[0].length && grid[x1][y1] == true) {
                dfs(grid, x1, y1);
            }
        }
    }
    public int numIslands(boolean[][] grid) {
        // Write your code here
        int num = 0;
        for (int i = 0; i < grid.length; i ++) {
            for (int j = 0; j < grid[0].length; j ++) {
                if (grid[i][j]) {
                    num ++;
                    dfs(grid, i, j);
                }
            }
        }
        return num;
    }
}
