#include <vector>

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int abs(int x, int y) {
        if (x - y > 0) return x - y;
        else return y - x;
    }
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        int len = A.size();
        if (len <= 1) return 0;
        vector<vector<int> > cost(len, vector<int> (101));
        for (int i = 0; i < len; i ++) {
            if (i == 0) {
                for (int j = 1; j <= 100; j ++) {
                    cost[i][j] = abs(A[i], j);
                }
            } else {
                for (int j = 1; j <= 100; j ++) {
                    cost[i][j] = INT_MAX;
                    for (int k = 1; k <= 100; k ++) {
                        if (abs(j, k) > target) continue;
                        int cnt = cost[i-1][k] + abs(A[i], j);
                        cost[i][j] = min(cost[i][j], cnt);
                    }
                }
            }
        }
        int res = INT_MAX;
        for (int i = 1; i <= 100; i ++) {
            res = min(res, cost[len-1][i]);
        }
        return res;
    }
};
