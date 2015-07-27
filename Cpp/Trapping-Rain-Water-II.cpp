class Cell {
public:
	int x, y, h;
	Cell() {}
	Cell(int xx, int yy, int hh) {
		x = xx;
		y = yy;
		h = hh;
	}
	bool operator < (const Cell &a) const {
        //按h由小到大排列，如果要由大到小排列，使用“>”即可；
        return a.h < h;
    }
};
 

class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        // write your code here
        if (heights.empty()) return 0;
        int lenx = heights.size(), leny = heights[0].size();
        priority_queue<Cell> q;
        vector<vector<int> > vis(lenx, vector<int>(leny));
        for (int i = 0; i < leny; i ++) {
        	q.push(Cell(0, i, heights[0][i]));
        	vis[0][i] = 1;
        	q.push(Cell(lenx - 1, i, heights[lenx - 1][i]));
        	vis[lenx - 1][i] = 1;
        }
        for (int i = 0; i < lenx; i ++) {
        	q.push(Cell(i, 0, heights[i][0]));
        	vis[i][0] = 1;
        	q.push(Cell(i, leny - 1, heights[i][leny - 1]));
        	vis[i][leny - 1] = 1;
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int res = 0;
        while (!q.empty()) {
        	Cell cur= q.top();
        	q.pop();
        	for (int i = 0; i < 4; i ++) {
        		int x1 = cur.x + dx[i];
        		int y1 = cur.y + dy[i];
        		int temph = cur.h;
        		if (x1 >= 0 && x1 < lenx && y1 >= 0 && y1 < leny && vis[x1][y1] == 0) {
        			vis[x1][y1] = 1;
        			q.push(Cell(x1, y1, max(temph, heights[x1][y1])));
        			res += max(0, temph - heights[x1][y1]);
        		}
        	}
        }
        return res;
    }
};
