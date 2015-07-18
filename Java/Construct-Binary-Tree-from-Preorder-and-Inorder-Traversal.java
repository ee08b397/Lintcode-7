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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
    public TreeNode helper(int[] preorder, int[] inorder, int l1, int r1, int l2, int r2) {
        if (l1 > r1) return null;
        if (l1 == r1) {
            TreeNode root = new TreeNode(preorder[l1]);
            return root;
        }
        int cur = 0;
        for (int i = l2; i <= r2; i ++) {
            if (inorder[i] == preorder[l1]) {
                cur = i;
                break;
            }
        }
        TreeNode root = new TreeNode(inorder[cur]);
        root.left = helper(preorder, inorder, l1 + 1, l1 + cur - l2, l2, cur - 1);
        root.right = helper(preorder, inorder, l1 + cur - l2 + 1, r1, cur + 1, r2);
        return root;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        // write your code here
        int len = preorder.length;
        return helper(preorder, inorder, 0, len - 1, 0, len - 1);
    }
}
