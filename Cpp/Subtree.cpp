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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSame(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL && T2 == NULL) return true;
        else if (T1 == NULL || T2 == NULL) return false;
        if (T1->val == T2->val) {
            return isSame(T1->left, T2->left) && isSame(T1->right, T2->right);
        } else return false;
    }
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if (T2 == NULL) return true;
        else if (T1 == NULL) return false;
        if (T1->val == T2->val) {
            if (isSame(T1, T2)) return true;
        }
        if (isSubtree(T1->left, T2) || isSubtree(T1->right, T2)) return true;
        return false;
    }
};

