class Solution:
    """
    @param n: An integer
    @return: An integer
    """
    def climbStairs(self, n):
        # write your code here
        if n <= 3:
            return n
        x = 1
        y = 2
        cur = 2
        while cur < n:
            temp = x + y
            x = y
            y = temp
            cur +=1
        return y