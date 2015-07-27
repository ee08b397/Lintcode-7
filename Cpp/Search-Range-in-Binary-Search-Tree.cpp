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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    void dfs(TreeNode *root, int k1, int k2, vector<int> &vec) {
        if (root == NULL) return;
        //if (root->val < k1 || root->val > k2) return;
        if (root->val > k1) dfs(root->left, k1, k2, vec);
        if (root->val >= k1 && root->val <= k2) vec.push_back(root->val);
        if (root->val < k2) dfs(root->right, k1, k2, vec);
    }
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> vec;
        dfs(root, k1, k2, vec);
        return vec;
    }
};
