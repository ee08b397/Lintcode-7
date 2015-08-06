class Solution:
    # @param {boolean[][]} grid a boolean 2D matrix
    # @return {int} an integer
    def dfs(self, grid, x, y):
        grid[x][y] = False
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        for i in xrange(4):
            x1 = x + dx[i]
            y1 = y + dy[i]
            if x1 >= 0 and x1 < len(grid) and y1 >= 0 and y1 < len(grid[0]) and grid[x1][y1]:
                self.dfs(grid, x1, y1)
    def numIslands(self, grid):
        # Write your code here
        if grid is None or len(grid) == 0:
            return 0
        res = 0
        lenx = len(grid)
        leny = len(grid[0])
        for i in xrange(lenx):
            for j in xrange(leny):
                if grid[i][j]:
                    res += 1
                    self.dfs(grid, i, j)
        return res