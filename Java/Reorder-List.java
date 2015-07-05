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
     * @return: void
     */
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
    public void merge(ListNode head, ListNode start) {
    	ListNode cur = new ListNode(-1);
    	int index = 0;
    	while (head != null && start != null) {
    		if (index % 2 == 0) {
    			cur.next = head;
    			head = head.next;
    		} else {
    			cur.next = start;
    			start = start.next;
    		}
    		cur = cur.next;
    		index ++;
    	}
    	if (head != null) {
    		cur.next = head;
    	} else {
    		cur.next = start;
    	}
    }
    public void reorderList(ListNode head) {  
        // write your code here
        if (head == null || head.next == null) return;
    	ListNode mid = FindMid(head);
    	ListNode start = mid.next;
    	mid.next = null;
    	start = reverse(start);
    	merge(head, start);
    }
}

