class Solution {
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    public void mergeSortedArray(int[] A, int m, int[] B, int n) {
        // write your code here
        int cur = m + n - 1, pa = m - 1, pb = n - 1;
        while (pa >= 0 && pb >= 0) {
        	if (A[pa] >= B[pb]) {
        		A[cur--] = A[pa--];
        	} else {
        		A[cur--] = B[pb--];
        	}
        }
        while (pa >= 0) {
        	A[cur--] = A[pa--];
        }
        while (pb >= 0) {
        	A[cur--] = B[pb--];
        }
        return;
    }
}
