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
     * @param x: an integer
     * @return: a ListNode 
     */
    public ListNode partition(ListNode head, int x) {
        // write your code here
        if (head == null) return null;
        ListNode LeftDummy = new ListNode(-1);
        ListNode RightDummy = new ListNode(-1);
        ListNode Leftcur = LeftDummy;
        ListNode Rightcur = RightDummy;
        while (head != null) {
        	if (head.val >= x) {
        		Rightcur.next = head;
        		Rightcur = Rightcur.next;
        	} else {
        		Leftcur.next = head;
        		Leftcur = Leftcur.next;
        	}
        	head = head.next;
        }
        Rightcur.next = null
        Leftcur.next = RightDummy.next;
        Leftcur = LeftDummy.next;
        return Leftcur;
    }
}

