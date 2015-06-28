/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    int find(int x, vector<int> &bin) {
    	int r = x, y = x;
    	while (r != bin[r]) {
    		r = bin[r];
    	}
    	while (y != r) {
    		int temp = bin[y];
    		bin[y] = r;
    		y = temp;
    	}
    	return r;
    }
    void merge(int x, int y, vector<int> &bin) {
    	int fx = find(x, bin), fy = find(y, bin);
    	if (fx != fy) bin[fx] = fy;
    }
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        // Write your code here
        vector<int> bin(m * n, -1);
        vector<int> res(operators.size());
        int cur = 0;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < operators.size(); i ++) {
        	int x = operators[i].x, y = operators[i].y, temp = x * m + y;
        	if (bin[temp] != -1) continue;
        	bin[temp] = temp;
        	//cur ++;
        	set<int> hash;
        	//hash.insert(temp);
        	for (int j = 0; j < 4; j ++) {
        		int x1 = x + dx[j], y1 = y + dy[j], t = x1 * m + y1;
        		if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && bin[t] != -1) {
        			int cnt = find(t, bin);
        			if(hash.find(cnt) == hash.end()) hash.insert(cnt);
        		}
        	}
            for (int j = 0; j < 4; j ++) {
                int x1 = x + dx[j], y1 = y + dy[j], t = x1 * m + y1;
                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && bin[t] != -1) {
                    merge(t, temp, bin);
                }
            }
        	cur += 1 - hash.size();
        	res[i] = cur;
        }
        return res;
    }
};


