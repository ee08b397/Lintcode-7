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
private:
    bool firstnode = true;
    int lastval = INT_MIN;
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        if (root == NULL) return true;
        if (!isValidBST(root->left)) return false;
        if (!firstnode && lastval >= root->val) return false;
        firstnode = false;
        lastval = root->val;
        if (!isValidBST(root->right)) return false;
        return true;
    }
};