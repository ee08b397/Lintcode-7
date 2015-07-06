/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    public RandomListNode copyRandomList(RandomListNode head) {
        // write your code here
        if (head == null) return null;
        RandomListNode cur = head;
        while (cur != null) {
        	RandomListNode temp = cur.next;
        	RandomListNode node = new RandomListNode(cur.label);
        	cur.next = node;
        	node.next = temp;
        	cur = temp;
        }
        cur = head;
        while (cur != null) {
        	RandomListNode temp = cur.next;
        	if (cur.random != null) temp.random = cur.random.next;
        	else temp.random = null;
        	cur = cur.next.next;
        }
        RandomListNode dummy = new RandomListNode(-1);
        RandomListNode cnt = dummy;
        cur = head;
        while (cur != null) {
        	cnt.next = cur.next;
        	cnt = cnt.next;
        	cur = cur.next.next;
        }
        cnt.next = null;
        return dummy.next;
    }
}
