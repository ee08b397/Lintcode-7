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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
    public TreeNode helper(int[] inorder, int[] postorder, int l1, int r1, int l2, int r2) {
        if (l1 > r1) return null;
        if (l1 == r1) {
            TreeNode root = new TreeNode(inorder[l1]);
            return root;
        }
        int cur = 0;
        for (int i = l1; i <= r1; i ++) {
            if (inorder[i] == postorder[r2]) {
                cur = i;
                break;
            }
        }
        TreeNode root = new TreeNode(inorder[cur]);
        root.left = helper(inorder, postorder, l1, cur - 1, l2, cur - l1  + l2 - 1);
        root.right = helper(inorder, postorder, cur + 1, r1, cur - l1 + l2, r2 - 1);
        return root;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        // write your code here
        int len = inorder.length;
        return helper(inorder, postorder, 0, len - 1, 0, len - 1);
    }
}
