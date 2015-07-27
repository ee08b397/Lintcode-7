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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        if (head == NULL) return NULL;
        ListNode *pre = new ListNode(-1), *cnt = pre, *res = head, *index;
        while (res != NULL) {
            index = pre;
            while (index->next != NULL && index->next->val <= res->val) {
                index = index->next;
            }
            cnt = res->next;
            res->next = index->next;
            index->next = res;
            res = cnt;
        }
        return pre->next;
    }
};
