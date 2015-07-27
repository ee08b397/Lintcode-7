#include <vector>
#include <queue>

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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    struct cmp{
        bool operator ()(const ListNode *a, const ListNode *b){
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        ListNode *pre = new ListNode(-1), *cnt = pre;
        for (int i = 0; i < lists.size(); i ++) {
            if (lists[i] != NULL) {
                que.push(lists[i]);
            }
        }
        while (!que.empty()) {
            cnt->next = que.top();
            cnt = cnt->next;
            if(que.top()->next != NULL) que.push(que.top()->next);
            que.pop();
        }
        cnt->next = NULL;
        return pre->next;
    }
};