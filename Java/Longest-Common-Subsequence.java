public class Solution {
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    public int longestCommonSubsequence(String A, String B) {
        // write your code here
        int lenA = A.length();
        int lenB = B.length();
        if (lenA == 0 || lenB == 0) return 0;
        int [][]lcs = new int[lenA + 1][lenB + 1];
        lcs[0][0] = 0;
        for (int i = 1; i <= lenA; i ++) {
        	for (int j = 1; j <= lenB; j ++) {
        		if (A.charAt(i - 1) == B.charAt(j - 1)) {
        			lcs[i][j] = lcs[i - 1][j - 1] + 1;
        		} else {
        			lcs[i][j] = Math.max(lcs[i - 1][j], lcs[i][j - 1]);
        		}
        	}
        }
        return lcs[lenA][lenB];
    }
}

