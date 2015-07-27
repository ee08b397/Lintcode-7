#include <vector>
#include <string>

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
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string int2str(int num) {
        string s = to_string(num);
        return s;
    }
    int str2int(string str) {
        return stoi( str );
    }
    void inorder(TreeNode *root, string &str) {
        if (root == NULL) return;
        inorder(root->left, str);
        str += (int2str(root->val) + "|");
        inorder(root->right, str);
    }
    void preorder(TreeNode *root, string &str) {
        if (root == NULL) return;
        str += (int2str(root->val) + "|");
        preorder(root->left, str);
        preorder(root->right, str);
    }
    string serialize(TreeNode *root) {
        // write your code here
        string str;
        preorder(root, str);
        inorder(root, str);
        return str;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
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
    TreeNode *deserialize(string data) {
        // write your code here
        int len = data.length() / 2;
        if (len == 0) return NULL;
        string str1 = data.substr(0, len), str2 = data.substr(len, len);
        vector<int> vec1, vec2;
        int sum = 0;
        for (int i = 0; i < str1.length(); i ++) {
            if (str1[i] == '|') {
                vec1.push_back(sum);
                sum = 0;
            } else {
                sum = sum * 10 + str1[i] - '0';
            }
        }
        for (int i = 0; i < str2.length(); i ++) {
            if (str2[i] == '|') {
                vec2.push_back(sum);
                sum = 0;
            } else {
                sum = sum * 10 + str2[i] - '0';
            }
        }
        return build(vec2, vec1, 0, vec2.size() - 1, 0, vec1.size() - 1);
    }
};

