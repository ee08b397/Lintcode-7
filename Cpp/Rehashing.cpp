#include <vector>

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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int len = hashTable.size(), newlen = 2 * len;
        vector<ListNode*> vec(newlen);
        for (int i = 0; i < len ; i++) {
            ListNode *cnt = hashTable[i];
            while (cnt != NULL) {
                int key = (cnt->val % newlen + newlen) % newlen;
                //ListNode *res = vec[key];
                ListNode *new_node = new ListNode(cnt->val);
                if (vec[key] == NULL) {
                    vec[key] = new_node;
                } else {
                    ListNode *res = vec[key];
                    while (res->next != NULL) {
                        res = res->next;
                    }
                    res->next = new_node;
                }
                cnt = cnt->next;
            }
        }
        return vec;
    }
};

