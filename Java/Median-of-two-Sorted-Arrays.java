class Solution {
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    public int FindKth(int[] A, int[] B, int startA, int startB, int k) {
        if (startA >= A.length) return B[startB + k - 1];
        if (startB >= B.length) return A[startA + k - 1];
        if (k == 1) return Math.min(A[startA], B[startB]);
        int A_key = startA + (k / 2) - 1 < A.length ? A[startA + (k / 2) - 1] : Integer.MAX_VALUE;
        int B_key = startB + (k / 2) - 1 < B.length ? B[startB + (k / 2) - 1] : Integer.MAX_VALUE;
        if (A_key < B_key) return FindKth(A, B, startA + k / 2, startB, k - k / 2);
        else return FindKth(A, B, startA, startB + k / 2, k - k / 2);
    }
    public double findMedianSortedArrays(int[] A, int[] B) {
        // write your code here
        int len = A.length + B.length;
        if ((len & 1) == 0) {
            return (FindKth(A, B, 0, 0, len / 2) + FindKth(A, B, 0, 0, len/ 2 + 1)) / 2.0;
        } else {
            return FindKth(A, B, 0, 0, len / 2 + 1);
        }
    }
}

