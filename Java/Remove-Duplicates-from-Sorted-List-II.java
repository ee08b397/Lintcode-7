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
     * @return: ListNode head of the linked list
     */
    public static ListNode deleteDuplicates(ListNode head) {
        // write your code here
        if (head == null || head.next == null) return head;
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        ListNode p = head;
        while (p != null) {
        	ListNode temp = p.next;
        	int num = 0;
        	while (temp != null && temp.val == p.val) {
        		num ++;
        		temp = temp.next;
        	}
        	if (num == 0) {
        		cur.next = p;
        		cur = cur.next;
        	}
        	p = temp;
        }
        cur.next = null;
        return dummy.next;
    }
}




