class Solution:
    """
    @param a, b, n: 32bit integers
    @return: An integer
    """
    def fastPower(self, a, b, n):
        # write your code here
        if n == 0:
            return 1 % b
        if n == 1:
            return a % b
        temp = n / 2
        cur = self.fastPower(a, b, temp)
        cur = (cur * cur) % b
        if n % 2 == 1:
            cur = (cur * a) % b
        return cur