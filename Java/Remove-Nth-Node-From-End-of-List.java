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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode removeNthFromEnd(ListNode head, int n) {
        // write your code here
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy;
        int cnt = 0;
        while (cnt < n) {
        	pre = pre.next;
        	cnt ++;
        }
        ListNode cur = dummy;
        while (pre.next != null) {
        	cur = cur.next;
        	pre = pre.next;
        }
        cur.next = cur.next.next;
        return dummy.next;
    }
}

