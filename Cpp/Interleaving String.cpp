#include <string>

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3) return false;
        vector<vector <int> > dp(len1 + 1 ,vector<int>(len2 + 1));
        dp[0][0] = 1;
        for (int i = 0; i <= len1; i ++) {
            for (int j = 0; j <= len2; j ++) {
                if (i > 0 && s1[i-1] == s3[i+j-1] && dp[i-1][j]) dp[i][j] = 1;
                if (j > 0 && s2[j-1] == s3[i+j-1] && dp[i][j-1]) dp[i][j] = 1;
            }
        }
        return dp[len1][len2];
    }
};
