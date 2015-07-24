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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    public TreeNode maxTree(int[] A) {
        // write your code here
        if (A == null || A.length == 0) return null;
        Stack<TreeNode> stk = new Stack<TreeNode>();
        stk.push(new TreeNode(A[0]));
        for (int i = 1; i < A.length; i ++) {
            if (A[i] < stk.peek().val) {
                stk.push(new TreeNode(A[i]));
            } else {
                TreeNode small_node = stk.pop();
                while (!stk.isEmpty() && stk.peek().val < A[i]) {
                    stk.peek().right = small_node;
                    small_node = stk.pop();
                }
                TreeNode temp = new TreeNode(A[i]);
                temp.left = small_node;
                stk.push(temp);
            }
        }
        TreeNode cur = stk.pop();
        while (!stk.isEmpty()) {
            stk.peek().right = cur;
            cur = stk.pop();
        }
        return cur;
    }
}
