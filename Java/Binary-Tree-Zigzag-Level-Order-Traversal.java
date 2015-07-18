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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
    public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
        // write your code here
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (root == null) return res;
        boolean sign = false;
        q.add(root);
        while (!q.isEmpty()) {
            ArrayList<Integer> cur = new ArrayList<Integer>();
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                TreeNode temp = q.poll();
                cur.add(temp.val);
                if (temp.left != null) q.add(temp.left);
                if (temp.right != null) q.add(temp.right);
            }
            if (sign) {
                Collections.reverse(cur);
            }
            sign = !sign;
            res.add(cur);
        }
        return res;
    }
}
