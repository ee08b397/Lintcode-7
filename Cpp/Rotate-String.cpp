#include <string>

class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    void reverse(string &A, int start, int end) {
        int mid = start + (end - start + 1) / 2;
        for (int i = start; i < mid; i++) {
            char ch = A[i];
            A[i] = A[end - (i - start)];
            A[end - (i - start)] = ch;
        }
    }
    string rotateString(string A, int offset) {
        // wirte your code here
        if (A.size() == 0) return A;
        offset = A.size() - offset % A.size();
        reverse(A, 0, offset - 1);
        reverse(A, offset, A.size() - 1);
        reverse(A, 0, A.size() - 1);
        return A;
    }
};
