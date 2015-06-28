class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    void dfs(vector<vector<bool> >& grid, int x, int y) {
    	grid[x][y] = false;
    	int dx[] = {0, 0, 1, -1};
    	int dy[] = {1, -1, 0, 0};
    	for (int i =0; i < 4; i ++) {
    		int x1 = x + dx[i];
    		int y1 = y + dy[i];
    		if (x1 >= 0 && x1 < grid.size() && y1 >= 0 && y1 < grid[0].size() && grid[x1][y1]) {
    			dfs(grid, x1, y1);
    		}
    	}
    }
    int numIslands(vector<vector<bool> >& grid) {
        // Write your code here
        int res = 0;
        for (int i = 0; i < grid.size(); i ++) {
        	for (int j = 0; j < grid[0].size(); j ++) {
        		if (grid[i][j]) {
        			res ++;
        			dfs(grid, i, j);
        		}
        	}
        }
        return res;
    }
};
