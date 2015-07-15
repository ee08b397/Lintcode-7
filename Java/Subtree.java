public class Solution {
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    public boolean issame(TreeNode T1, TreeNode T2) {
        if (T1 == null && T2 == null) return true;
        if (T1 == null || T2 == null) return false;
        if (T1.val == T2.val && issame(T1.left, T2.left) && issame(T1.right, T2.right)) return true;
        return false;
    }
    public boolean isSubtree(TreeNode T1, TreeNode T2) {
        if (T2 == null) return true;
        if (T1 == null) return false;
        if (T1.val == T2.val) {
            if (issame(T1, T2)) return true;
        }
        if (isSubtree(T1.left, T2) || isSubtree(T1.right, T2)) return true;
        return false;
    }
}