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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        if (node == NULL) return;
        while (node->next != NULL) {
            node->val = node->next->val;
            if (node->next->next == NULL) node->next = NULL;
            else node = node->next;
        }
    }
};
