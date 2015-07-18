#include <deque>
#include <vector>

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> res;
        if (k == 0 || nums.empty()) return res;
        deque<int> deq;
        for (int i = 0; i < k; i ++) {
            while (!deq.empty() && nums[i] >= nums[deq.back()]) {
                deq.pop_back();
            }
            deq.push_back(i);
        }
        int len = nums.size();
        for (int i = k; i < len; i ++) {
            res.push_back(nums[deq.front()]);
            while (!deq.empty() && nums[i] >= nums[deq.back()]) {
                deq.pop_back();
            }
            while (!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }
            deq.push_back(i);
        }
        res.push_back(nums[deq.front()]);
        return res;
    }
};

class Solution2 {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    class SegmentTreeNode {
    public:
        int start, end, max;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int start, int end, int max) {
            this->start = start;
            this->end = end;
            this->max = max;
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
        root->max = max(root->left->max, root->right->max);
        return root;
    }
    void modify(int pos, int val, SegmentTreeNode *root) {
        if (root->start == root->end) {
            root->max = val;
            return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (pos <= mid) modify(pos, val, root->left);
        else modify(pos, val, root->right);
        root->max = max(root->left->max, root->right->max);
    }
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> res;
        if (k <= 0 || nums.empty()) return res;
        int len = nums.size();
        SegmentTreeNode *root = build(0, min(k - 1, len - 1), nums);
        res.push_back(root->max);
        for (int i = k; i < nums.size(); i ++) {
            modify(i % k, nums[i], root);
            res.push_back(root->max);
        }
        return res;
    }
};

class Solution3 {
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



