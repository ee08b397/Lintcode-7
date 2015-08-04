class Solution:
    # @param n a integer
    # @return ans a integer
    def trailingZeros(self, n):
        res = 0
        while n != 0:
            res += n / 5
            n = n / 5
        return res