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
     * @return: buttom-up level order a list of lists of integer
     */
    public ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
        // write your code here
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (root == null) return res;
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
            res.add(cur);
        }
        Collections.reverse(res);
        return res;
    }
}
