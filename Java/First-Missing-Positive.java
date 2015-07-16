public class Solution {
    /**
     * @param A: an array of integers
     * @return: an integer
     */
    public int firstMissingPositive(int[] A) {
        // write your code here
        for (int i = 0; i < A.length;) {
            int temp = A[i];
            if (temp > 0 && temp <= A.length && A[temp - 1] != temp) {
                int cur = A[temp - 1];
                A[temp - 1] = temp;
                A[i] = cur;
            } else {
                i ++;
            }
        }
        for (int i = 0; i < A.length; i ++) {
            if (i + 1 != A[i]) return i + 1;
        }
        return A.length + 1;
    }
}