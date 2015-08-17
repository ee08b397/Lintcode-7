class Solution:
    # @param A, a list of integers
    # @return an integer
    def firstMissingPositive(self, A):
        # write your code here
        N = len(A)
        for i in xrange(N):
            while A[i] > 0 and A[i] <= N and A[i] != i + 1:
                if A[A[i] - 1] == A[i]:
                    break
                temp = A[A[i] - 1]
                A[A[i] - 1] = A[i]
                A[i] = temp
        for i in xrange(N):
            if A[i] != i + 1:
                return i + 1
        return N + 1