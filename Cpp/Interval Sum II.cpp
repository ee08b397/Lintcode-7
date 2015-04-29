#include <vector>

class Solution {
public:
    /* you may need to use some attributes here */

    /**
     * @param A: An integer vector
     */
    class SegmentTreeNode {
    public:
        int start, end;
        long long val;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int start, int end, long long val) {
            this->start = start, this->end = end, this->val = val;
            this->left = this->right = NULL;
        }
    };
    SegmentTreeNode *root;
    SegmentTreeNode * build(int start, int end, vector<int> &A) {
        // write your code here
        if (start > end) return NULL;
        if (start == end) {
            SegmentTreeNode *root = new SegmentTreeNode(start, end, A[start]);
            return root;
        }
        int mid = start + (end - start) / 2;
        SegmentTreeNode *root = new SegmentTreeNode(start, end, A[mid]);
        root->left = build(start, mid, A);
        root->right = build(mid + 1, end, A);
        root->val = root->left->val + root->right->val;
        return root;
    }
    long long modifyval(SegmentTreeNode *root) {
        if (root->start == root->end) return root->val;
        else return root->val = modifyval(root->left) + modifyval(root->right);
    }
    void modifynode(SegmentTreeNode *root, int index, int value) {
        if (root->start == root->end && root->end == index) {
            root->val = value;
            return;
        } else {
            int mid = root->start + (root->end - root->start) / 2;
            if (index <= mid) {
                modifynode(root->left, index, value);
                root->val = root->left->val + root->right->val;
            }
            else {
                modifynode(root->right, index, value);
                root->val = root->left->val + root->right->val;
            }
        }
    }
    long long queryval(SegmentTreeNode *root, int start, int end) {
        if (start <= root->start && end >= root->end) return root->val;
        else {
            int mid = root->start + (root->end - root->start) / 2;
            if (start > mid) return queryval(root->right, start, end);
            else if(end <= mid) return queryval(root->left, start, end);
            else return queryval(root->left, start, mid) + queryval(root->right, mid + 1, end);
        }
    }
    Solution(vector<int> A) {
        // write your code here
        root = build(0, A.size() - 1, A);
    }
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return queryval(root, start, end);
    }
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        modifynode(root, index, value);
    }
};

