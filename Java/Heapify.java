public class Solution {
    /**
     * @param A: Given an integer array
     * @return: void
     */
    public void helper(int[] A, int pos) {
        int left, right;
        if (pos * 2 + 1 >= A.length) left = Integer.MAX_VALUE;
        else left = A[pos * 2 + 1];
        if (pos * 2 + 2 >= A.length) right = Integer.MAX_VALUE;
        else right = A[pos * 2 + 2];
        if (left < right && A[pos] > left) {
            A[pos * 2 + 1] = A[pos];
            A[pos] = left;
            helper(A, pos * 2 + 1);
        } else if (A[pos] > right) {
            A[pos * 2 + 2] = A[pos];
            A[pos] = right;
            helper(A, pos * 2 + 2);
        }
    }
    public void heapify(int[] A) {
        // write your code here
        for (int i = A.length / 2 - 1; i >= 0; i--) {
            helper(A, i);
        }
    }
}
