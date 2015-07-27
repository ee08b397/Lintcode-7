/**
 * Definition of TreeNode:
 **/
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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    void solve(TreeNode* root, TreeNode *node) {
        if (node->val < root->val) {
            if (root->left == NULL) root->left = node;
            else solve(root->left, node);
        } else if (node->val > root->val) {
            if (root->right == NULL) root->right = node;
            else solve(root->right, node);
        }
        return;
    }
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if (root == NULL) return node;
        solve(root, node);
        return root;
    }
};
