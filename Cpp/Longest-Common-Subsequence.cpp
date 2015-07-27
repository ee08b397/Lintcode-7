class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int m = A.size(), n = B.size();
        vector<vector<int> > vec(m+1, vector<int>(n+1));
        vec[0][0] = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (A[i] == B[j]) {
                    vec[i+1][j+1] = vec[i][j] + 1;
                } else {
                    vec[i+1][j+1] = max(vec[i][j+1], vec[i+1][j]);
                }
            }
        }
        return vec[m][n];
    }
};
