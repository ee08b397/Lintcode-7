/**
 * Definition of SegmentTreeNode:
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


class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    int dfs(SegmentTreeNode *root) {
        if (root->left != NULL && root->right != NULL) return root->max = max(dfs(root->left), dfs(root->right));
        else if (root->left != NULL) return root->max = dfs(root->left);
        else if (root->right != NULL) return root->max = dfs(root->right);
        else return root->max;
    }
    void modifyval(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (root->start == root->end) {
            root->max = value;
            return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (index <= mid) modify(root->left, index, value);
        if (index > mid) modify(root->right, index, value);
    }
    void modify(SegmentTreeNode *root, int index, int value) {
        modifyval(root, index, value);
        dfs(root);
    }
};
