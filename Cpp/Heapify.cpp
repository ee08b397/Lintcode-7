#include <vector>

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void solve(int pos, vector<int> &A) {
        int left , right;
        if (pos * 2 + 1 >= A.size()) left = INT_MAX;
        else left = A[pos * 2 + 1];
        if (pos * 2 + 2 >= A.size()) right = INT_MAX;
        else right = A[pos * 2 + 2];
        if (left < right && left < A[pos]) {
            A[2 * pos + 1] = A[pos];
            A[pos] = left;
            solve(2 * pos + 1, A);
        } else if (right < A[pos]) {
            A[2 * pos + 2] = A[pos];
            A[pos] = right;
            solve(2 * pos + 2, A);
        }
    }
    void heapify(vector<int> &A) {
        // write your code here
        for (int i = A.size() / 2 - 1; i >= 0; i --) {
            solve(i, A);
        }
    }
};
