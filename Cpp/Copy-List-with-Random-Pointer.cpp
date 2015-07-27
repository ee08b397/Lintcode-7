#include <map>

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode* pre = new RandomListNode(-1);
        RandomListNode *cnt = pre, *node = head;
        map<int, RandomListNode*> hash;
        while (node != NULL) {
            RandomListNode *temp = new RandomListNode(node->label);
            hash[temp->label] = temp;
            node = node->next;
            cnt->next = temp;
            cnt = cnt->next;
        }
        cnt->next = NULL;
        node = head, cnt = pre->next;
        while (node != NULL) {
            if (node->random != NULL) {
                cnt->random = hash[node->random->label];
            } else {
                cnt->random = NULL;
            }
            node = node->next;
            cnt = cnt->next;
        }
        return pre->next;
    }
};
