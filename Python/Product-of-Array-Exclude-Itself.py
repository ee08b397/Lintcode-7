class Solution:
    """
    @param A: Given an integers array A
    @return: An integer array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
    """
    def productExcludeItself(self, A):
        # write your code here
        seq = [1] * len(A)
        for i in xrange(1, len(A)):
            seq[i] = seq[i - 1] * A[i - 1]
        cur = 1
        for i in xrange(len(A) - 2, -1, -1):
            cur = cur * A[i + 1]
            seq[i] *= cur
        return seq