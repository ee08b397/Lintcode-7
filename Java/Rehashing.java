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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    public ListNode[] rehashing(ListNode[] hashTable) {
        // write your code here
        int capacity = hashTable.length * 2;
        ListNode[] res = new ListNode[capacity];
        for (int i = 0; i < hashTable.length; i ++) {
            ListNode cur = hashTable[i];
            while (cur != null) {
                int key = (cur.val % capacity + capacity) % capacity;
                ListNode new_node = new ListNode(cur.val);
                if (res[key] == null) {
                    res[key] = new_node;
                } else {
                    ListNode temp = res[key];
                    while(temp.next != null) {
                        temp = temp.next;
                    }
                    temp.next = new_node;
                }
                cur = cur.next;
            }
        }
        return res;
    }
};

