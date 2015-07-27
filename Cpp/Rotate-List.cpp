/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if (k == 0 || head == NULL) return head;
        int num = 0;
        ListNode *node = head;
        ListNode *prev = new ListNode(0);
        while (node != NULL) {
            prev->next = node;
            prev = prev->next;
            node = node->next;
            num += 1;
        }
        if (num == 1 || k % num == 0) return head;
        int cnt = num - (k % num) - 1;
        node = head;
        for (int i = 0; i < cnt; i ++){
            node = node->next;
        }
        ListNode *node1 = node->next;
        node->next = NULL;
        prev->next = head;
        return node1;
    }
};
