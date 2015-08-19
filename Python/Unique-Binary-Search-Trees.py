class Solution:
    # @paramn n: An integer
    # @return: An integer
    def numTrees(self, n):
        # write your code here
        if n == 0:
            return 1
        if n <= 2:
            return n
        seq = [0] * (n + 1)
        seq[0] = seq[1] = 1
        for i in xrange(2, n + 1):
            for j in xrange(0, i):
                seq[i] += seq[j] * seq[i - 1 - j]
        return seq[n]
