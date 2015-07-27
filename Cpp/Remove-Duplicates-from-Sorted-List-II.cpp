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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if (head == NULL) return head;
        map<int, int> st;
        ListNode *node = head;
        while (node != NULL) {
            if (st.find(node->val) != st.end()) st[node->val] ++;
            else st[node->val] = 1;
            node = node->next;
        }
        node = head;
        ListNode *pre = new ListNode(0);
        ListNode *res = pre;
        while (node != NULL) {
            if (st[node->val] == 1) {
                pre->next = node;
                pre = pre->next;
            }
            node = node->next;
        }
        pre->next = NULL;
        return res->next;
    }
};
