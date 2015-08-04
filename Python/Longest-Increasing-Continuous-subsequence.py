class Solution:
    # @param {int[]} A an array of Integer
    # @return {int}  an integer
    def longestIncreasingContinuousSubsequence(self, A):
        # Write your code here
        if A is None or len(A) <= 0:
            return 0
        declen = 1
        inclen = 1
        maxlen = 1
        for i in range(1, len(A)):
            if A[i] >= A[i - 1]:
                inclen += 1
            else:
                inclen = 1
            if A[i] <= A[i - 1]:
                declen += 1
            else:
                declen = 1
            maxlen = max(maxlen, max(declen, inclen))
        return maxlen