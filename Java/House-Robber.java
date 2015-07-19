public class Solution {
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    public long houseRobber(int[] A) {
        // write your code here
        if (A == null || A.length == 0) return 0;
        if (A.length == 1) return A[0];
        long pa = A[0], pb = Math.max(A[0], A[1]);
        for (int i = 2; i < A.length; i ++) {
            long temp = Math.max(pb, pa + A[i]);
            pa = pb;
            pb = temp;
        }
        return pb;
    }
}