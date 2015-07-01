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
     * @param A: an integer array
     * @return: a tree node
     */
    public TreeNode build(int[] A, int left, int right) {
    	if (left > right) return null;
    	if (left == right) {
    		TreeNode root = new TreeNode(A[left]);
    		return root;
    	}
    	int mid = left + (right - left) / 2;
    	TreeNode root = new TreeNode(A[mid]);
    	root.left = build(A, left, mid - 1);
    	root.right = build(A, mid + 1, right);
    	return root;
    }
    public TreeNode sortedArrayToBST(int[] A) {  
        // write your code here
        //int left = 0, right = A.length() - 1;
        return build(A, 0, A.length - 1);
    }  
}

