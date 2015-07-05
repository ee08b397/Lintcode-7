/**
 * Definition for ListNode
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param ListNode head is the head of the linked list
     * @return: ListNode head of linked list
     */
    public static ListNode deleteDuplicates(ListNode head) { 
        // write your code here
        if (head == null || head.next == null) return head;
        ListNode cnt = head;
        ListNode cur = head.next;
        int temp = head.val;
        while (cur != null) {
        	if (cur.val != temp) {
        		temp = cur.val;
        		cnt.next = cur;
        		cnt = cnt.next;
        	}
        	cur = cur.next;
        }
        cnt.next = null;
        return head;
    }
}
