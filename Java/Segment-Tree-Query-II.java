/**
 * Definition of SegmentTreeNode:
 * public class SegmentTreeNode {
 *     public int start, end, count;
 *     public SegmentTreeNode left, right;
 *     public SegmentTreeNode(int start, int end, int count) {
 *         this.start = start;
 *         this.end = end;
 *         this.count = count;
 *         this.left = this.right = null;
 *     }
 * }
 */
public class Solution {
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end]
     */
    public int query(SegmentTreeNode root, int start, int end) {
        // write your code here
        if (root == null) return 0;
        if (start > root.end || end < root.start) return 0;
        if (start <= root.start && end >= root.end) return root.count;
        int mid = root.start + (root.end - root.start) / 2;
        if (end <= mid) return query(root.left, start, end);
        else if (start > mid) return query(root.right, start, end);
        return query(root.left, start, mid) + query(root.right, mid + 1, end);
    }
}
