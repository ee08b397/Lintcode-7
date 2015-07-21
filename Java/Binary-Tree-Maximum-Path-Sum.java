/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: An integer.
     */
    private int maxv = Integer.MIN_VALUE;
    public int helper(TreeNode root) {
        if (root == null) return 0;
        int leftv = helper(root.left);
        int rightv = helper(root.right);
        int temp = Math.max(root.val, Math.max(root.val + leftv, root.val + rightv));
        maxv = Math.max(maxv, Math.max(temp, root.val + rightv + leftv));
        return temp;
    }
    public int maxPathSum(TreeNode root) {
        // write your code here
        helper(root);
        return maxv;
    }
}
