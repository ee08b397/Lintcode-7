class Solution:
    """
    @param A: sorted integer array A which has m elements,
              but size of A is m+n
    @param B: sorted integer array B which has n elements
    @return: void
    """
    def mergeSortedArray(self, A, m, B, n):
        # write your code here
        cur = m + n - 1
        pa = m - 1
        pb = n - 1
        while pa >= 0 and pb >= 0:
            if A[pa] < B[pb]:
                A[cur] = B[pb]
                pb -= 1
                cur -= 1
            else:
                A[cur] = A[pa]
                pa -= 1
                cur -= 1
        while pb >= 0:
            A[cur] = B[pb]
            pb -= 1
            cur -= 1
