class Solution {
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    ArrayList<String> DrawMap(int[][] map) {
        ArrayList<String> res = new ArrayList<String>();
        for (int i = 0; i < map.length; i ++) {
            StringBuffer sb = new StringBuffer();
            for (int j = 0; j < map.length; j ++) {
                if (map[i][j] == 1) sb.append("Q");
                else sb.append(".");
            }
            res.add(sb.toString());
        }
        return res;
    }
    public void helper(ArrayList<ArrayList<String>> res, int[][] map, int[][] vis, int pos, int n) {
        if (pos == n) {
            res.add(DrawMap(map));
            return;
        }
        for (int i = 0; i < n; i ++) {
            if (vis[0][i] == 0 && vis[1][pos + i] == 0 && vis[2][n - i + pos] == 0) {
                vis[0][i] = vis[1][pos + i] = vis[2][n - i + pos] = 1;
                map[pos][i] = 1;
                helper(res, map, vis, pos + 1, n);
                vis[0][i] = vis[1][pos + i] = vis[2][n - i + pos] = 0;
                map[pos][i] = 0;
            }
        }
    }
    ArrayList<ArrayList<String>> solveNQueens(int n) {
        // write your code here
        ArrayList<ArrayList<String>> res = new ArrayList<ArrayList<String>>();
        if (n == 0) return res;
        int[][] map = new int[n][n];
        int[][] vis = new int[3][30];
        helper(res, map, vis, 0, n);
        return res;
    }
};