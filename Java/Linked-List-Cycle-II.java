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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    public ListNode detectCycle(ListNode head) {
        // write your code here
        if (head == null || head.next == null) return null;
        ListNode slow = head;
        ListNode fast = head.next;
        int len = 1;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            len ++;
            if (slow == fast) break;
        }
        if (fast == null || fast.next == null) return null;
        ListNode cur = head;
        slow = head;
        for (int i = 0; i < len; i ++) {
            cur = cur.next;
        }
        while (slow != cur) {
            slow = slow.next;
            cur = cur.next;
        }
        return cur;
    }
}

