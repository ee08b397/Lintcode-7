#include <vector>
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
    vector<TreeNode*> generate(int left, int right) {
        if(left > right) return  vector<TreeNode*>(1, nullptr);
        vector<TreeNode*> vec;
        for(int k = left; k <= right; k++){
            vector<TreeNode*> lt = generate(left, k - 1);
            vector<TreeNode*> rt = generate(k + 1, right);
            for(int i = 0; i < lt.size(); i++){
                for(int j = 0; j < rt.size(); j++){
                    TreeNode *root = new TreeNode(k);
                    root->left = lt[i];
                    root->right = rt[j];
                    vec.push_back(root);
                }
            }
        }
        return vec;
    }

    vector<TreeNode *> generateTrees(int n){
        return generate(1, n);
    }
};