public class Solution {
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    public int smallestDifference(int[] A, int[] B) {
        // write your code here
        Arrays.sort(A);
        Arrays.sort(B);
        int pa = 0, pb = 0, mind = Integer.MAX_VALUE;
        while (pa < A.length && pb < B.length) {
            mind = Math.min(mind, Math.abs(A[pa] - B[pb]));
            if (A[pa] == B[pb]) return 0;
            else if (A[pa] < B[pb]) pa ++;
            else pb ++;
        }
        return mind;
    }
}