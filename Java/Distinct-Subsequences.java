public class Solution {
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    public int numDistinct(String S, String T) {
        // write your code here
        int len1 = S.length();
        int len2 = T.length();
        if (len1 == 0 || len2 == 0) return 0;
        int [][]dp = new int[len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; i ++) {
            for (int j = 0; j <= len2; j ++) {
                if (i < j) {
                    dp[i][j] = 0;
                } else if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else if (S.charAt(i - 1) == T.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len1][len2];
    }
}
