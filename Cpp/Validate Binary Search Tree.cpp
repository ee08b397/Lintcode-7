/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    void inorder(TreeNode *root, vector<int> &vec) {
        if (root == NULL) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    bool isValidBST(TreeNode *root) {
        // write your code here
        vector<int> vec;
        inorder(root, vec);
        for (int i = 1; i < vec.size(); i ++) {
            if (vec[i] <= vec[i-1]) return false;
        }
        return true;
    }
};
