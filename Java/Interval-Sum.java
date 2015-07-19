/**
 * Definition of Interval:
 * public classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 */
public class Solution {
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    public class SegmentTreeNode {
        public int start, end;
        long val;
        public SegmentTreeNode left, right;
        public SegmentTreeNode(int start, int end, long val) {
            this.start = start;
            this.end = end;
            this.val = val;
            this.left = this.right = null;
        }
    }
    public SegmentTreeNode build(int start, int end, int[] A) {
        // write your code here
        if (start > end) return null;
        if (start == end) {
            SegmentTreeNode root = new SegmentTreeNode(start, start, A[start]);
            return root;
        }
        int mid = start + (end - start) / 2;
        SegmentTreeNode root = new SegmentTreeNode(start, end, 0);
        root.left = build(start, mid, A);
        root.right = build(mid + 1, end, A);
        root.val = root.left.val + root.right.val;
        return root;
    }
    public long query(int start, int end, SegmentTreeNode root) {
        if (start == root.start && end == root.end) return root.val;
        int mid = root.start + (root.end - root.start) / 2;
        if (end <= mid) return query(start, end, root.left);
        else if (start > mid) return query(start, end, root.right);
        else return query(start, mid, root.left) + query(mid + 1, end, root.right);
    }
    public ArrayList<Long> intervalSum(int[] A,
                                                ArrayList<Interval> queries) {
        // write your code here
        ArrayList<Long> res = new ArrayList<Long>();
        SegmentTreeNode root = build(0, A.length - 1, A);
        for (int i = 0; i < queries.size(); i ++) {
            res.add(query(queries.get(i).start, queries.get(i).end, root));
        }
        return res;
    }
}
