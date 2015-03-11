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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        int d = 0;
        ListNode *pre = new ListNode(0);
        ListNode *res = pre;
        while (l1 != NULL && l2 != NULL) {
            ListNode *cnt = new ListNode((l1->val + l2->val + d) % 10);
            d = (l1->val + l2->val + d) / 10;
            res->next = cnt;
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            ListNode *cnt = new ListNode((l1->val + d) % 10);
            d = (l1->val + d) / 10;
            res->next = cnt;
            res = res->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            ListNode *cnt = new ListNode((l2->val + d) % 10);
            d = (l2->val + d) / 10;
            res->next = cnt;
            res = res->next;
            l2 = l2->next;
        }
        if (d != 0) {
            ListNode *cnt= new ListNode(d);
            res->next = cnt;
            res = res->next;
        }
        res->next = NULL;
        return pre->next;
    }
};
