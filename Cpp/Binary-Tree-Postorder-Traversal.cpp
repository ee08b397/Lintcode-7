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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    void postorder(TreeNode *root, vector<int> &vec) {
        if (root == NULL) return;
        postorder(root->left, vec);
        postorder(root->right, vec);
        vec.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> vec;
        postorder(root, vec);
        return vec;
    }
};
