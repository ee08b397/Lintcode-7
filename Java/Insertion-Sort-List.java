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
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    public ListNode insertionSortList(ListNode head) {
        // write your code here
        if (head == null || head.next == null) return head;
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        cur.next = head;
        head = head.next;
        dummy.next.next = null;
        while (head != null) {
        	ListNode temp = dummy;
        	ListNode cnt = head.next;
        	while (temp.next != null && temp.next.val < head.val) {
        		temp = temp.next;
        	}
        	ListNode p = temp.next;
        	temp.next = head;
        	head.next = p;
        	head = cnt;
        }
        return dummy.next;
    }
}
