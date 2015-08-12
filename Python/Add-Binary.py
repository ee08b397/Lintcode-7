class Solution:
    # @param {string} a a number
    # @param {string} b a number
    # @return {string} the result
    def addBinary(self, a, b):
        # Write your code here
        pa = len(a) - 1
        pb = len(b) - 1
        s = ""
        d = 0
        while pa >= 0 and pb >= 0:
            cur = d + int(a[pa]) + int(b[pb])
            pa -= 1
            pb -= 1
            s += str(cur % 2)
            d = cur / 2
        while pa >= 0:
            cur = d + int(a[pa])
            pa -= 1
            s += str(cur % 2)
            d = cur / 2
        while pb >= 0:
            cur = d + int(b[pb])
            pb -= 1
            s += str(cur % 2)
            d = cur / 2
        if d > 0:
            s += str(d)
        rs = ""
        for i in range(len(s)):
            rs += s[len(s) - 1 - i]
        return rs