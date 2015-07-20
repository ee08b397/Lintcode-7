public class Solution {
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    public boolean canJump(int[] A) {
        // wirte your code here
        int maxlen = 0;
        for (int i = 0; i <= maxlen && i < A.length; i ++) {
            maxlen = Math.max(maxlen, A[i] + i);
            if (maxlen >= A.length - 1) return true;
        }
        return false;
    }
}
