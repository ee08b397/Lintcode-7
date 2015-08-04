class Solution:
    # @param {int} n the integer to be reversed
    # @return {int} the reversed integer
    def reverseInteger(self, n):
        # Write your code here
        res = 0
        sign = 1
        maxv = (1 << 31) - 1
        if n < 0:
            n = -n
            sign = -1
        while n != 0:
            temp = n % 10
            res = res * 10 + temp
            n = n / 10
            if res > maxv and sign == 1:
                return 0
            if res > (maxv + 1) and sign == -1:
                return 0
        return res * sign
