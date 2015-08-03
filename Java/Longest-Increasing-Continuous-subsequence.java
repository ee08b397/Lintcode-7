public class Solution {
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    public int longestIncreasingContinuousSubsequence(int[] A) {
        // Write your code here
        if (A == null || A.length <= 0) return 0;
        int len = A.length;
        int maxlen = 1, increlen = 1, decrelen = 1;
        for (int i = 1; i < len; i ++) {
            if (A[i] >= A[i - 1]) {
                increlen ++;
            } else {
                increlen = 1;
            }
            if (A[i] <= A[i - 1]) {
                decrelen ++;
            } else {
                decrelen = 1;
            }
            maxlen = Math.max(maxlen, Math.max(decrelen, increlen));
        }
        return maxlen;
    }
}
