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
    void dfs(TreeNode root, ArrayList<Integer> res) {
    	if (root == null) return;
    	dfs(root.left, res);
    	res.add(root.val);
    	dfs(root.right, res);
    }
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        // write your code here
        ArrayList res = new ArrayList();
        dfs(root, res);
        return res;
    }
}
