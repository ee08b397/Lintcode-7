class Solution:
    # @param num: an integer
    # @return: an integer, the number of ones in num
    def countOnes(self, num):
        # write your code here
        res = 0
        while num != 0:
            res += 1
            num = num & (num - 1)
        return res