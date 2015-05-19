#include <vector>
/**
 * Definition of TreeNode:
 */
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *build(vector<int> &A, int left, int right) {
        if (left > right) return NULL;
        if (left == right) {
            TreeNode *root = new TreeNode(A[left]);
            return root;
        }
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(A[mid]);
        root->left = build(A, left, mid - 1);
        root->right = build(A, mid + 1, right);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if (A.empty()) return 0;
        return build(A, 0, A.size() - 1);
    }
};