#include <vector>

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        if (A.empty()) return 0;
        int len = A.size(), m = 1, res = 1;
        for (int i = 1; i < len; i ++) {
            if (A[i] > A[i-1]) {
                m += 1;
                res = max(res, m);
            } else {
                m = 1;
            }
        }
        m = 1;
        for (int i = len - 2; i >= 0; i --) {
            if (A[i] > A[i+1]) {
                m += 1;
                res = max(res, m);
            } else {
                m = 1;
            }
        }
        return res;
    }
};
