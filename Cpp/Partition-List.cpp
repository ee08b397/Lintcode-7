/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode *pre1 = new ListNode(0);
        ListNode *pre2 = new ListNode(0);
        ListNode *node = head;
        ListNode *res1 = pre1, *res2 = pre2;
        while (node != NULL) {
            if (node->val < x) {
                pre1->next = node;
                pre1 = pre1->next;
                node = node->next;
            } else {
                pre2->next = node;
                pre2 = pre2->next;
                node = node->next;
            }
        }
        pre1->next = NULL;
        pre2->next = NULL;
        if (res1->next == NULL) return res2->next;
        else if(res2->next == NULL) return res1->next;
        else {
            pre1->next = res2->next;
            return res1->next;
        }
    }
};
