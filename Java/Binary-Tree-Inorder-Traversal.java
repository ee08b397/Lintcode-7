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
     * @return: Inorder in ArrayList which contains node values.
     */
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        // write your code here
        Stack<TreeNode> stk = new Stack<TreeNode>();
        ArrayList<Integer> res = new ArrayList<Integer>();
        if (root == null) return res;
        while (!stk.isEmpty() || root != null) {
            while (root != null) {
                stk.push(root);
                root = root.left;
            }
            if (!stk.isEmpty()) {
                root = stk.peek().right;
                res.add(stk.pop().val);
            }
        }
        return res;
    }
}
