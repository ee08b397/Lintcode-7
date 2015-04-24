#include <vector>

/**
 * Definition of TreeNode:
 **/
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
    /**
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int pos1, int pos2, int pos3, int pos4) {
        if (pos1 > pos2) return NULL;
        if (pos1 == pos2) {
            TreeNode *root = new TreeNode(inorder[pos1]);
            return root;
        }
        int index;
        for (int i = pos2; i >= pos1; i --) {
            if (postorder[pos4] == inorder[i]) {
                index = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(postorder[pos4]);
        root->left = build(inorder, postorder, pos1, index - 1, pos3, pos3 + index - 1 - pos1);
        root->right = build(inorder, postorder, index + 1, pos2, pos3 + index - pos1, pos4 - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if (inorder.size() == 0) return NULL;
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
