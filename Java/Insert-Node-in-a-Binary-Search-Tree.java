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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    public TreeNode insertNode(TreeNode root, TreeNode node) {
        // write your code here
        if (root == null) return node;
        TreeNode cur = root;
        while (cur != null) {
        	if (node.val == cur.val) return root;
        	if (node.val > cur.val) {
        		if (cur.right == null) {
        			cur.right = node;
        			return root;
        		} else {
        			cur = cur.right;
        		}
        	} else {
        		if (cur.left == null) {
        			cur.left = node;
        			return root;
        		} else {
        			cur = cur.left;
        		}
        	}
        }
        return root;
    }
}
