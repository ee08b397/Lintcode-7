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
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // write your code here
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        while (l1 != null && l2 != null) {
        	if (l1.val <= l2.val) {
        		cur.next = l1;
        		cur = cur.next;
        		l1 = l1.next;
        	} else {
        		cur.next = l2;
        		cur = cur.next;
        		l2 = l2.next;
        	}
        }
        if (l1 == null) {
        	cur.next = l2;
        } else {
        	cur.next = l1;
        }
        return dummy.next;
    }
    public ListNode FindMid(ListNode head) {
    	if (head == null) return null;
    	ListNode slow = head;
    	ListNode fast = head.next;
    	while (fast != null && fast.next != null) {
    		fast = fast.next.next;
    		slow = slow.next;
    	}
    	return slow;
    }
    public ListNode sortList(ListNode head) {
        // write your code here
        if (head == null || head.next == null) return head;
        ListNode mid = FindMid(head);
        ListNode start = mid.next;
        mid.next = null;
        return mergeTwoLists(sortList(head), sortList(start));
    }
}
