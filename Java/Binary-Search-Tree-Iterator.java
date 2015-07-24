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
 * Example of iterate a tree:
 * Solution iterator = new Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode node = iterator.next();
 *    do something for node
 * } 
 */
public class Solution {
    //@param root: The root of binary tree.
    private Stack<TreeNode> stk;
    public Solution(TreeNode root) {
        // write your code here
        stk = new Stack<TreeNode>();
        while (root != null) {
            stk.push(root);
            root = root.left;
        }
    }

    //@return: True if there has next node, or false
    public boolean hasNext() {
        // write your code here
        return !stk.isEmpty();
    }

    //@return: return next node
    public TreeNode next() {
        // write your code here
        TreeNode cur = stk.pop();
        TreeNode temp = cur.right;
        while (temp != null) {
            stk.push(temp);
            temp = temp.left;
        }
        return cur;
    }
}
