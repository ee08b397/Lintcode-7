#include <vector>

/**
 * Definition of Interval:
 */
class Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
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
        return root;
    }
    void modify(SegmentTreeNode* root) {
        if (root->start == root->end) return;
        modify(root->left);
        modify(root->right);
        root->val = root->left->val + root->right->val;
        return;
    }
    long long query(Interval res, SegmentTreeNode *root) {
        if (res.start <= root->start && res.end >= root->end) return root->val;
        else {
            int mid = root->start + (root->end - root->start) / 2;
            if (res.start > mid) return query(res, root->right);
            else if (res.end <= mid) return query(res, root->left);
            else {
                return query(Interval(res.start, mid), root->left) + query(Interval(mid + 1, res.end), root->right);
            }
        }
    }
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<long long> vec;
        SegmentTreeNode *root = build(0, A.size() - 1, A);
        modify(root);
        for (int i = 0; i < queries.size(); i ++) {
            vec.push_back(query(queries[i], root));
        }
        return vec;
    }
};
