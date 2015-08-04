class Solution:
    """
    @param a, b: Two integer
    return: An integer
    """
    def bitSwapRequired(self, a, b):
        # write your code here
        cur = a ^ b
        res = 0
        while cur != 0:
            res += 1
            cur = (cur & (cur - 1))
        return res
