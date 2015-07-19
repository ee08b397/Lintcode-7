public class Solution {
    /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    public class SegmentTreeNode {
        public int start, end, max, min;
        public SegmentTreeNode left, right;
        public SegmentTreeNode(int start, int end, int max, int min) {
            this.start = start;
            this.end = end;
            this.max = max;
            this.min = min;
            this.left = this.right = null;
        }
    }
    public SegmentTreeNode build(int[] A, int start, int end) {
        if (start > end) return null;
        if (start == end) {
            SegmentTreeNode root = new SegmentTreeNode(start, start, A[start], A[start]);
            return root;
        }
        SegmentTreeNode root = new SegmentTreeNode(start, end, A[end], A[start]);
        int mid = start + (end - start) / 2;
        root.left = build(A, start, mid);
        root.right = build(A, mid + 1, end);
        return root;
    }
    public int query(SegmentTreeNode root, int num) {
        if (root == null) return 0;
        if (root.max < num) return root.end - root.start + 1;
        if (root.min >= num) return 0;
        int mid = root.start + (root.end - root.start);
        return query(root.left, num) + query(root.right, num);
    }
    public ArrayList<Integer> countOfSmallerNumber(int[] A, int[] queries) {
        // write your code here
        Arrays.sort(A);
        ArrayList<Integer> res = new ArrayList<Integer>();
        SegmentTreeNode root = build(A, 0, A.length - 1);
        for (int i = 0; i < queries.length; i ++) {
            res.add(query(root, queries[i]));
        }
        return res;
    }
}