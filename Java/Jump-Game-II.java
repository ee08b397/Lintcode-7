public class Solution {
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    public int jump(int[] A) {
        // write your code here
        if (A == null || A.length == 0) return 0;
        int len = A.length;
        int[] steps = new int[len];
        steps[0] = 0;
        for (int i = 1; i < A.length; i ++) {
            steps[i] = Integer.MAX_VALUE;
            for (int j = 0; j < i; j ++) {
                if (steps[j] != Integer.MAX_VALUE && j + A[j] >= i) {
                    steps[i] = steps[j] + 1;
                    break;
                }
            }
        }
        return steps[len - 1];
    }
}