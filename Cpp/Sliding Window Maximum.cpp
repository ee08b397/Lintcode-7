#include <vector>

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    class SegmentTreeNode {
    public:
        int start, end, val;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int start, int end, int val) {
            this->start = start, this->end = end, this->val = val;
            this->left = this->right = NULL;
        }
    };
    SegmentTreeNode *build(vector<int> &nums, int start, int end) {
        if (start > end) return NULL;
        if (start == end) {
            SegmentTreeNode* root = new SegmentTreeNode(start, end, nums[start]);
            return root;
        }
        int mid = start + (end - start) / 2;
        SegmentTreeNode *root = new SegmentTreeNode(start, end, nums[mid]);
        root->left = build(nums, start, mid);
        root->right = build(nums, mid + 1, end);
        root->val = max(root->left->val, root->right->val);
        return root;
    }
    int query(int start, int end, SegmentTreeNode *root) {
        if (start <= root->start && end >= root->end) return root->val;
        else {
            int mid = root->start + (root->end - root->start) / 2;
            if (start > mid) return query(start, end, root->right);
            else if (end <= mid) return query(start, end, root->left);
            else {
                return max(query(start, mid, root->left), query(mid + 1, end, root->right));
            }
        }
    }
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        SegmentTreeNode *root = build(nums, 0, nums.size() - 1);
        vector<int> vec;
        for (int i = 0; i + k - 1 < nums.size(); i ++) {
            vec.push_back(query(i, i + k - 1, root));
        }
        return vec;
    }
};

