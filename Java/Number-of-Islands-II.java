/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
public class Solution {
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    public int[] bin;
    public int find(int x) {
        int y = x;
        while (bin[y] != y) {
            y = bin[y];
        }
        while (x != y) {
            int temp = bin[x];
            bin[x] = y;
            x = temp;
        }
        return y;
    }
    public void merge(int x, int y) {
        int fx = find(x), fy= find(y);
        if (fx != fy) {
            bin[fx] = fy;
        }
    }
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    public List<Integer> numIslands2(int n, int m, Point[] operators) {
        // Write your code here
        bin = new int[n * m];
        List<Integer> res = new ArrayList<Integer>();
        if (operators == null) return res;
        Arrays.fill(bin, -1);
        int cur = 0;
        for (int i = 0; i < operators.length; i ++) {
            int x = operators[i].x, y = operators[i].y, pos = x * m + y;
            if (bin[pos] != -1) continue;
            bin[pos] = pos;
            HashSet<Integer> hash = new HashSet<Integer>();
            for (int j = 0; j < 4; j ++) {
                int x1 = x + dx[j], y1 = y + dy[j], temp = x1 * m + y1;
                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && bin[temp] != -1) {
                    int cnt = find(temp);
                    if (!hash.contains(cnt)) hash.add(cnt);
                }
            }
            for (int j = 0; j < 4; j ++) {
                int x1 = x + dx[j], y1 = y + dy[j], temp = x1 * m + y1;
                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && bin[temp] != -1) {
                    merge(temp, pos);
                }
            }
            cur += (1 - hash.size());
            res.add(cur);
        }
        return res;
    }
}