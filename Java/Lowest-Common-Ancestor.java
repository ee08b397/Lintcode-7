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
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    public boolean cover(TreeNode root, TreeNode node) {
        if (root == null) return false;
        if (root == node) return true;
        if (cover(root.left, node) || cover(root.right, node)) return true;
        return false;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode A, TreeNode B) {
        // write your code here
        while (true) {
            if (root == A || root == B) return root;
            boolean lcoverA = cover(root.left, A);
            boolean lcoverB = cover(root.left, B);
            if (lcoverA && lcoverB) root = root.left;
            else if (!lcoverA && !lcoverB) root = root.right;
            else return root;
        }
        //return root;
    }
}
