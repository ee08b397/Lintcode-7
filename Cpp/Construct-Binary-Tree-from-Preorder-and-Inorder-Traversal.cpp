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
    TreeNode *build(vector<int> &inorder, vector<int> &preorder, int pos1, int pos2, int pos3, int pos4) {
        if (pos1 > pos2) return NULL;
        if (pos1 == pos2) {
            TreeNode *root = new TreeNode(inorder[pos1]);
            return root;
        }
        int index;
        for (int i = pos2; i >= pos1; i --) {
            if (preorder[pos3] == inorder[i]) {
                index = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(preorder[pos3]);
        root->left = build(inorder, preorder, pos1, index - 1, pos3 + 1, pos3 + index - pos1);
        root->right = build(inorder, preorder, index + 1, pos2, pos3 + index - pos1 + 1, pos4);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if (inorder.size() == 0) return NULL;
        return build(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }
};
