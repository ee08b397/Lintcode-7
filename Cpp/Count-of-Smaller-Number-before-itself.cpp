#include <vector>

class Solution {
public:
    class SegmentTreeNode {
    public:
        int start, end, count;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int start, int end, int count) {
            this->start = start;
            this->end = end;
            this->count = count;
            this->left = this->right = NULL;
        }
    };

    /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    SegmentTreeNode *buildLeft(int start, int end) {
        SegmentTreeNode *node = new SegmentTreeNode(start, end, 1);
        if(start == end) return node;
        node->left = new SegmentTreeNode(start, start, 1);
        node->right = new SegmentTreeNode(start+1, end, 0);
        return node;
    }
    int update(SegmentTreeNode *&node, int val) {
        if(val > node->end) {
            int res = node->count;
            SegmentTreeNode *head = new SegmentTreeNode(node->start, val, node->count+1);
            head->right = new SegmentTreeNode(node->end+1, val, 1);
            head->left = node;
            node = head;
            return res;
        }
        if(val < node->start) {
            SegmentTreeNode *head = new SegmentTreeNode(val, node->end, node->count+1);
            head->left = buildLeft(val, node->start-1);
            head->right = node;
            node = head;
            return 0;
        }
        node->count ++;
        if(node->left) {
            if(node->left->end >= val) return update(node->left, val);
            return update(node->right, val) + node->left->count;
        } else {
            node->left = new SegmentTreeNode(node->start, val, 1);
            node->right = new SegmentTreeNode(val+1, node->end, node->count);
        }
        return 0;
    }
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        int len = A.size();
        vector<int> res(len,0);
        if(0 == len)return res;
        SegmentTreeNode * root = new SegmentTreeNode(A[0], A[0], 1);
        for(int i = 1; i < len; i++) {
            res[i] = update(root, A[i]);
        }
        return res;
    }
};

