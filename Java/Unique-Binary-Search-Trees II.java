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
     * @paramn n: An integer
     * @return: A list of root
     */
    public List<TreeNode> helper(int left, int right) {
        if (left > right) {
            List<TreeNode> res = new LinkedList<TreeNode>();
            res.add(null);
            return res;
        }
        List<TreeNode> res = new LinkedList<TreeNode>();
        for (int i = left; i <= right; i ++) {
            List<TreeNode> lt = helper(left, i - 1);
            List<TreeNode> rt = helper(i + 1, right);
            for (int j = 0; j < lt.size(); j ++) {
                for (int k = 0; k < rt.size(); k ++) {
                    TreeNode root = new TreeNode(i);
                    root.left = lt.get(j);
                    root.right = rt.get(k);
                    res.add(root);
                }
            }
        }
        return res;
    }
    public List<TreeNode> generateTrees(int n) {
        // write your code here
        return helper(1, n);
    }
}
