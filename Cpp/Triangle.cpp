class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int len = triangle.size();
        if (len == 0 || triangle[0].empty()) return 0;
        vector<int> dp(len);
        for (int i = 0; i < len; i ++) {
        	dp[i] = triangle[len - 1][i];
        }
        for (int i = len - 2; i >= 0; i --) {
        	for (int j = 0; j <= i; j ++) {
        		dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        	}
        }
        return dp[0];
    }
};

