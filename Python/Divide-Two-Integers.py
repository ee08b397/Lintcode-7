class Solution:
    # @param {int} dividend the dividend
    # @param {int} divisor the divisor
    # @return {int} the result
    def divide(self, dividend, divisor):
        # Write your code here
        int_max = 2147483647
        if divisor == 0:
            return int_max
        sign = 1
        if dividend * divisor < 0:
            sign = -1
        divisor = abs(divisor)
        dividend = abs(dividend)
        res = 0
        while dividend >= divisor:
            cur = 1
            mul = divisor
            while dividend >= (mul << 1):
                cur = cur << 1
                mul = mul << 1
            res += cur
            dividend = dividend - mul
            if res >= int_max and sign == 1:
                return int_max
        return res * sign