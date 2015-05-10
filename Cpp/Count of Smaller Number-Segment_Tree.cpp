#include <vector>
#include <algorithm>

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    class SegmentTreeNode {
    public:
        int start, end, minval, maxval;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int start, int end, int minval, int maxval) {
            this->start = start, this->end = end;
            this->minval = minval, this->maxval = maxval;
        }
    };
    SegmentTreeNode* build(int start, int end, vector<int> &A) {
        if (start > end) return NULL;
        if (start == end) {
            SegmentTreeNode *res = new SegmentTreeNode(start, end, A[start], A[start]);
            return res;
        }
        int mid = start + (end - start) / 2;
        SegmentTreeNode *root = new SegmentTreeNode(start, end, A[mid], A[mid]);
        root->left = build(start, mid, A);
        root->right = build(mid + 1, end, A);
        root->minval = min(root->left->minval, root->right->minval);
        root->maxval = max(root->left->maxval, root->right->maxval);
        return root;
    }
    int query(int val, SegmentTreeNode *root) {
        if (root == NULL) return 0;
        if (val > root->maxval) {
            return root->end - root->start + 1;
        } else if (val <= root->minval) {
            return 0;
        } else {
            return query(val, root->left) + query(val, root->right);
        }
    }
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> vec;
        sort(A.begin(), A.end());
        SegmentTreeNode *root = build(0 , A.size() - 1, A);
        for (int i = 0; i < queries.size(); i ++) {
            vec.push_back(query(queries[i], root));
        }
        return vec;
    }
};
