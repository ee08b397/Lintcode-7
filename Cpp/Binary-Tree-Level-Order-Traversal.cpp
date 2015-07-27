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
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > res;
        if (root == NULL) return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> cur;
            for (int i = 0; i < size; i ++) {
                TreeNode *temp = q.front();
                q.pop();
                cur.push_back(temp->val);
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
            res.push_back(cur);
        }
        return res;
    }
};

