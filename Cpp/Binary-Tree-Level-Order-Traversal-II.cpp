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
    vector<vector<int> > levelOrderButtom(TreeNode *root) {
        // write your code here
        vector<vector<int> > vec;
        if (root == NULL) return vec;
        queue<TreeNode*> q1,q2;
        TreeNode *res;
        q1.push(root);
        while (!q1.empty() || !q2.empty()) {
            vector<int> st;
            if (!q1.empty()) {
                while (!q1.empty()) {
                    res = q1.front();
                    if (res->left != NULL) q2.push(res->left);
                    if (res->right != NULL) q2.push(res->right);
                    q1.pop();
                    st.push_back(res->val);
                }
                vec.push_back(st);
            }
            else {
                while (!q2.empty()) {
                    res = q2.front();
                    if (res->left != NULL) q1.push(res->left);
                    if (res->right != NULL) q1.push(res->right);
                    q2.pop();
                    st.push_back(res->val);
                }
                vec.push_back(st);
            }
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};
