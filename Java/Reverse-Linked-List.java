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
 */ 
public class Solution {
    /**
     * @param head: The head of linked list.
     * @return: The new head of reversed linked list.
     */
    public ListNode reverse(ListNode head) {
        // write your code here
        ListNode cur = null;
        ListNode cnt = head;
        while (cnt != null) {
        	ListNode temp = cnt.next;
        	cnt.next = cur;
        	cur = cnt;
        	cnt = temp;
        }
        return cur;
    }
}

