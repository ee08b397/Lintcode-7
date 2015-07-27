/**
 * Definition of ListNode
 */
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
     * @return: The node where the cycle begins.
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if (head == NULL || head ->next == NULL) return NULL;
        ListNode *node1 = head, *node2 = head;
        node1 = node1->next;
        node2 = (node2->next)->next;
        if (node2 == NULL) return NULL;
        int cnt = 1;
        while (node1 != node2) {
            node1 = node1->next;
            node2 = node2->next;
            if (node2 == NULL) return NULL;
            node2 = node2->next;
            if (node2 == NULL) return NULL;
            cnt ++;
        }
        ListNode *node = head;
        for (int i = 0; i < cnt; i ++) {
            node = node->next;
        }
        node1 = head;
        while (node != node1) {
            node = node->next;
            node1 = node1->next;
        }
        return node;
    }
};
