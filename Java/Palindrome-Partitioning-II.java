public class Solution {
    /**
     * @param s a string
     * @return an integer
     */
    public int minCut(String s) {
        // write your code here
        int len = s.length();
        if (len <= 1) return 0;
        boolean [][]dp = new boolean[len][len];
        for (int i = 0; i < len; i ++) {
            dp[i][i] = true;
        }
        for (int i = 2; i <= len; i ++) {
            for (int j = 0; j + i - 1 < len; j ++) {
                int k = j + i - 1;
                dp[j][k] = false;
                if ((k - 1 <= j + 1 || dp[j + 1][k - 1]) && s.charAt(j) == s.charAt(k)) {
                    dp[j][k] = true;
                }
            }
        }
        int []cut = new int[len];
        cut[0] = 0;
        for (int i = 1; i < len; i ++) {
            cut[i] = i;
            if (dp[0][i]) {
                cut[i] = 0;
                continue;
            }
            for (int j = 1; j <= i; j ++) {
                if (dp[j][i]) {
                    cut[i] = Math.min(cut[i], cut[j - 1] + 1);
                }
            }
        }
        return cut[len - 1];
    }
};
