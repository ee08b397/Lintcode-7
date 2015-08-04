class Solution:
    # @param {int[]} digits a number represented as an array of digits
    # @return {int[]} the result
    def plusOne(self, digits):
        # Write your code here
        d = 1
        cur = len(digits) - 1
        res = []
        while cur >= 0:
            temp = digits[cur] + d
            d = temp / 10
            res.append(temp % 10)
            cur -= 1
        if d > 0:
            res.append(d)
        res.reverse()
        return res
