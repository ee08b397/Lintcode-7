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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return head;
        ListNode *node = head, *node1 = node->next;
        while (node1 != NULL) {
            if (node1->val == node->val) {
                node1 = node1->next;
            } else {
                node->next = node1;
                node = node->next;
                node1 = node1->next;
            }
        }
        node->next = NULL;
        return head;
        // write your code here
    }
};
