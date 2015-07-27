#include <vector>

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int cnt = A[0], n = A.size();
        for(int i = 1; i <= cnt; i++) {
            if (A[i] + i > cnt) cnt = A[i] + i;
            if (cnt >= n - 1) return true;
        }
        return false;
    }
};

