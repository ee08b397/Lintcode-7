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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    int dfs(TreeNode *root) {
        if (root == NULL) return 0;
        else return max(dfs(root->left), dfs(root->right)) + 1;
    }
    bool isBalanced(TreeNode *root) {
        // write your code here
        if (root == NULL) return true;
        if (abs(dfs(root->left) - dfs(root->right)) > 1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
};
