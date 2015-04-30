#include <stack>

/**
 * Definition of singly-linked-list:
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
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if (m == n) return head;
        ListNode *cnt = head;
        ListNode *pre = new ListNode(-1), *res = pre;
        for (int i = 0; i < m - 1; i ++) {
            res->next = cnt;
            res = cnt;
            cnt = cnt->next;
        }
        stack<ListNode*> st;
        for (int i = 0; i <= n - m; i ++) {
            st.push(cnt);
            cnt = cnt->next;
        }
        while (!st.empty()) {
            res->next = st.top();
            res = res->next;
            st.pop();
        }
        res->next = cnt;
        return pre->next;
    }
};

