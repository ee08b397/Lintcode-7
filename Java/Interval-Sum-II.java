public class Solution {
    /* you may need to use some attributes here */
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
    private SegmentTreeNode root;
    /**
     * @param A: An integer array
     */
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
    public long Query(int start, int end, SegmentTreeNode root) {
        if (start == root.start && end == root.end) return root.val;
        int mid = root.start + (root.end - root.start) / 2;
        if (end <= mid) return Query(start, end, root.left);
        else if (start > mid) return Query(start, end, root.right);
        else return Query(start, mid, root.left) + Query(mid + 1, end, root.right);
    }
    public void modifyR(int index, int value, SegmentTreeNode root) {
        if (index == root.start && index == root.end) {
            root.val = value;
            return;
        }
        int mid = root.start + (root.end - root.start) / 2;
        if (index <= mid) modifyR(index, value, root.left);
        else if (index > mid) modifyR(index, value, root.right);
        root.val = root.left.val + root.right.val;
    }
    public Solution(int[] A) {
        // write your code here
        root = build(0, A.length - 1, A);
    }

    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    public long query(int start, int end) {
        // write your code here
        return Query(start, end, root);
    }

    /**
     * @param index, value: modify A[index] to value.
     */
    public void modify(int index, int value) {
        // write your code here
        modifyR(index, value, root);
    }
}