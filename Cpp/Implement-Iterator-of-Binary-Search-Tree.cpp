#include <stack>
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
/**
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    stack<TreeNode*> st;
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !st.empty();
    }
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode *cur = st.top(), *cnt = cur;
        st.pop();
        cnt = cnt->right;
        while (cnt != NULL) {
            st.push(cnt);
            cnt = cnt->left;
        }
        return cur;
    }
};
