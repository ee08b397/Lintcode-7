#include <vector>

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        if (A.empty()) return 0;
        vector<long long> cnt(2);
        if (A.size() == 1) return A[0];
        cnt[0] = A[0], cnt[1] = max(A[0], A[1]);
        for (int i = 2; i < A.size(); i ++) {
            long long temp = max(cnt[1], cnt[0] + A[i]);
            cnt[0] = cnt[1];
            cnt[1] = temp;
        }
        return cnt[1];
    }
};
