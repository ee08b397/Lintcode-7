/**
 * Definition of ListNode
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        stack<ListNode*> st;
        ListNode *pre = new ListNode(0);
        ListNode *res = pre;
        while (head != NULL) {
            st.push(head);
            head = head->next;
        }
        while (!st.empty()) {
            res->next = st.top();
            st.pop();
            res = res->next;
        }
        res->next = NULL;
        return pre->next;
    }
};
