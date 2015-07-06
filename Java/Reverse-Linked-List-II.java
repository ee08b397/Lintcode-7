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
     * @oaram m and n
     * @return: The head of the reversed ListNode
     */
    public ListNode reverseBetween(ListNode head, int m , int n) {
        // write your code
        if (m == n) return head;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode start = dummy;
        for (int i = 0; i < m - 1; i ++) {
        	start = start.next;
        }
        ListNode cur = start.next;
        ListNode end = cur;
        for (int i = 0; i < n - m; i ++) {
        	end = end.next;
        }
        ListNode cnt = end.next;
        end.next = null;
        while (cur != null) {
        	ListNode temp = cur.next;
        	cur.next = cnt;
        	cnt = cur;
        	cur = temp;
        }
        start.next = cnt;
        return dummy.next;
    }
}