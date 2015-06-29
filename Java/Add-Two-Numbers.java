/**
 * Definition for singly-linked list.
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    public ListNode addLists(ListNode l1, ListNode l2) {
        // write your code here
        ListNode pre = new ListNode(-1), cur = pre;
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        int carry = 0, num = 0;
        while (l1 != null && l2 != null) {
        	num = carry + l1.val + l2.val;
        	carry = num / 10;
        	num = num % 10;
        	l1.val = num;
        	cur.next = l1;
        	l1 = l1.next;
        	l2 = l2.next;
        	cur = cur.next;
        }
        while (l1 != null) {
        	num = carry + l1.val;
        	carry = num / 10;
        	num = num % 10;
        	l1.val = num;
        	cur.next = l1;
        	l1 = l1.next;
        	cur = cur.next;
        }
        while (l2 != null) {
        	num = carry + l2.val;
        	carry = num / 10;
        	num = num % 10;
        	l2.val = num;
        	cur.next = l2;
        	l2 = l2.next;
        	cur = cur.next;
        }
        if (carry != 0) {
        	ListNode temp = new ListNode(carry);
        	cur.next = temp;
        }
        return pre.next;
    }
}
