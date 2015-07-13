public class Solution {
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    class Point {
        int x, y, val;
        Point() { x = 0; y = 0; val = 0; }
        Point(int a, int b, int c) { x = a; y = b; val = c; }
        Point(Point r) { x = r.x; y = r.y; val = r.val; }
    }
    private Comparator<Point> PointComparator = new Comparator<Point>() {
        public int compare(Point left, Point right) {
            return left.val - right.val;
        }
    };
    public int kthSmallest(int[][] matrix, int k) {
        // write your code here
        int lenx = matrix.length, leny = matrix[0].length;
        PriorityQueue<Point> q = new PriorityQueue<Point>(leny, PointComparator);
        for (int i = 0; i < leny; i ++) {
            q.add(new Point(0, i, matrix[0][i]));
        }
        int res = 0;
        while (!q.isEmpty()) {
            int dx = q.peek().x + 1, dy = q.peek().y, dv = q.peek().val;
            res ++;
            if (res == k) {
                return dv;
            }
            q.poll();
            if (dx < lenx) {
                q.add(new Point(dx, dy, matrix[dx][dy]));
            }
        }
        return -1;
    }
}
