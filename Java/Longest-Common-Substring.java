public class Solution {
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    public int longestCommonSubstring(String A, String B) {
        // write your code here
        int lenA = A.length();
        int lenB = B.length();
        if (lenA == 0 || lenB == 0) return 0;
        int [][]res = new int[lenA + 1][lenB + 1];
        for (int i = 0; i <= lenA; i ++) {
        	res[i][0] = 0;
        }
        for (int i = 0; i <= lenB; i ++) {
        	res[0][i] = 0;
        }
        int maxlen = 0;
        for (int i = 1; i <= lenA; i ++) {
        	for (int j = 1; j <= lenB; j ++) {
        		if (A.charAt(i - 1) == B.charAt(j - 1)) {
        			res[i][j] = res[i - 1][j - 1] + 1;
        			maxlen = Math.max(res[i][j], maxlen);
        		} else {
        			res[i][j] = 0;
        		}
        	}
        }
        return maxlen;
    }
}
