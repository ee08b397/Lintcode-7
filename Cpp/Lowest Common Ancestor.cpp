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
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    void dfs(TreeNode *root, string str, map<TreeNode*, string> &st) {
        st[root] = str;
        if (root->left != NULL) {
            string s = str + "1";
            dfs(root->left, s, st);
        }
        if (root->right != NULL) {
            string s = str + "0";
            dfs(root->right, s, st);
        }
    }
    TreeNode *solve(TreeNode *root, string &str, int pos, int end) {
        if (pos == end) return root;
        if (str[pos] == '1') return solve(root->left, str, pos+1, end);
        else return solve(root->right, str, pos+1, end);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        map<TreeNode*, string> st;
        string str = "1";
        dfs(root, str, st);
        string str1 = st[A], str2 = st[B];
        str = "";
        for (int i = 0; i < str1.size() && i < str2.size(); i ++) {
            if (str1[i] == str2[i]) str += str1[i];
            else break;
        }
        return solve(root, str, 1, str.size());
    }
};
