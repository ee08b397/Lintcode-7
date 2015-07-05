/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    public TreeNode sortedListToBST(ListNode head) {  
        // write your code here
        if (head == null) return null;
        if (head.next == null) {
        	TreeNode root = new TreeNode(head.val);
        	return root;
        }
        ListNode prev = null;
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
        	prev = slow;
        	slow = slow.next;
        	fast = fast.next.next;
        }
        ListNode temp = slow.next;
        TreeNode root = new TreeNode(slow.val);
        if (prev != null) {
        	prev.next = null;
        	root.left = sortedListToBST(head);
        }
        root.right = sortedListToBST(temp);
        return root;
    }
}




