#include <vector>
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

class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        stack<TreeNode*> stk;
        stk.push(new TreeNode(A[0]));
        for (int i = 1; i < A.size(); i ++) {
            if (A[i] < stk.top()->val) {
                stk.push(new TreeNode(A[i]));
            } else {
                TreeNode *small_node = stk.top();
                stk.pop();
                while (!stk.empty() && stk.top()->val < A[i]) {
                    stk.top()->right = small_node;
                    small_node = stk.top();
                    stk.pop();
                }
                TreeNode *node = new TreeNode(A[i]);
                node->left = small_node;
                stk.push(node);
            }
        }
        TreeNode *root = stk.top();
        stk.pop();
        while (!stk.empty()) {
            stk.top()->right = root;
            root = stk.top();
            stk.pop();
        }
        return root;
    }
};
