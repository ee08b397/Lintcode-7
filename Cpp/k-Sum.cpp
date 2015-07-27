#include <vector>

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        int len = A.size();
        //sort(A.begin(), A.end());
        vector<vector<vector<int> > > dp(len + 1, vector<vector<int> >(k + 1, vector<int>(target + 1)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= len; i ++) {
            for (int j = 0; j <= k && j <= i; j ++) {
                for (int v = 0; v <= target; v ++) {
                    if (v >= A[i-1] && j > 0) dp[i][j][v] += dp[i-1][j-1][v-A[i-1]];
                    dp[i][j][v] += dp[i-1][j][v];
                }
            }
        }
        return dp[len][k][target];
    }
};
