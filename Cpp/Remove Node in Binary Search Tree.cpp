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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    int FindLeftMin(TreeNode *root) {
        if (root->left == NULL) return root->val;
        else return FindLeftMin(root->left);
    }
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if (root == NULL) return NULL;
        int res = root->val;
        if (res > value) root->left = removeNode(root->left, value);
        else if (res < value) root->right = removeNode(root->right, value);
        else {
            if (root->left != NULL && root->right != NULL) {
                root->val = FindLeftMin(root->right);
                root->right = removeNode(root->right, root->val);
            } else if (root->left != NULL) {
                 root = root->left;
            } else root = root->right;
        }
        return root;
    }
};
