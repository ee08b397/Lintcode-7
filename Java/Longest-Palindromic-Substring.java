public class Solution {
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    public String longestPalindrome(String s) {
        // Write your code here
        int len = s.length();
        boolean [][] dp = new boolean[len][len];
        for (int i = 0; i < len; i ++) {
            dp[i][i] = true;
        }
        int maxlen = 1, left = 0, right = 0;
        for (int i = 2; i <= len; i ++) {
            for (int j = 0; j + i <= len; j ++) {
                int k = j + i - 1;
                dp[j][k] = false;
                if (s.charAt(j) == s.charAt(k) && (j + 1 >= k - 1 || dp[j + 1][k - 1])) {
                    dp[j][k] = true;
                    if (maxlen < i) {
                        maxlen = i;
                        left = j;
                        right = k;
                    }
                }
            }
        }
        return s.substring(left, right + 1);
    }
}
