#include <vector>

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findKth(vector<int> &A, vector<int> &B, int leftA, int lenA, int leftB, int lenB, int k) {
        if (lenA > lenB) return findKth(B, A, leftB, lenB, leftA, lenA, k);
        if (lenA == 0) return B[leftB + k - 1];
        if (k == 1) return min(A[leftA], B[leftB]);
        int pa = min(lenA, k / 2), pb = k - pa;
        if (A[leftA + pa - 1] < B[leftB + pb - 1]) {
            return findKth(A, B, leftA + pa, lenA - pa, leftB, lenB, k - pa);
        } else if (A[leftA + pa - 1] > B[leftB + pb - 1]) {
            return findKth(A, B, leftA, lenA, leftB + pb, lenB - pb, k - pb);
        } else {
            return A[leftA + pa - 1];
        }
    }
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        // write your code here
        int len = A.size() + B.size();
        if (len & 0x1) return findKth(A, B, 0, A.size(), 0, B.size(), len / 2 + 1);
        else return (findKth(A, B, 0, A.size(), 0, B.size(), len / 2)
            + findKth(A, B, 0, A.size(), 0, B.size(), len / 2 + 1)) / 2;
    }
};

