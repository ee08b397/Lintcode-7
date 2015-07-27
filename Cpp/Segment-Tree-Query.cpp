/**
 * Definition of SegmentTreeNode:
 */
class SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (start <= root->start && end >= root->end) return root->max;
        else {
            int mid = root->start + (root->end - root->start) / 2;
            if (start > mid) return query(root->right, start, end);
            else if(end <= mid) return query(root->left, start, end);
            else return max(query(root->left, start, mid), query(root->right, mid + 1, end));
        }
    }
};
