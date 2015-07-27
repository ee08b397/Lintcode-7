/**
 * Definition of ListNode
 **/
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list.
     */
    ListNode *nthToLast(ListNode *head, int n) {
        ListNode *node = head;
        if (n == 0) return NULL;
        while (n - 1 > 0) {
            if (node == NULL) return NULL;
            node = node->next;
            n--;
        }
        while (node->next != NULL) {
            head = head->next;
            node = node->next;
        }
        return head;
        // write your code here
    }
};