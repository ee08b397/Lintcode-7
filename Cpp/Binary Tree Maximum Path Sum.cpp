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
     * @return: An integer
     */
    class ResultType {
    public:
        int singlePath, maxPath;
        ResultType(int singlePath, int maxPath) {
            this->singlePath = singlePath;
            this->maxPath = maxPath;
        }
    };
    ResultType helper(TreeNode *root) {
        if (root == NULL) {
            return ResultType(0, INT_MIN);
        }
        //divide
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);
        //conquer
        int singlePath = max(left.singlePath, right.singlePath) + root->val;
        singlePath = max(singlePath, 0);

        int maxPath = max(left.maxPath, right.maxPath);
        maxPath = max(maxPath, left.singlePath + right.singlePath + root->val);
        return ResultType(singlePath, maxPath);
    }
    int maxPathSum(TreeNode *root) {
        // write your code here
        ResultType result = helper(root);
        return result.maxPath;
    }
};
