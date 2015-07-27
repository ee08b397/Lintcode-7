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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> vec;
        if (root == NULL) return vec;
        stack<TreeNode*> st;
        TreeNode *cnt = root;
        while (!st.empty() || cnt != NULL) {
            while (cnt != NULL) {
                st.push(cnt);
                vec.push_back(cnt->val);
                cnt = cnt->left;
            }
            cnt = st.top();
            st.pop();
            //vec.push_back(cnt->val);
            cnt = cnt->right;
        }
        return vec;
    }
};
