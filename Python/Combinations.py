class Solution:
    """
    @param n: Given the range of numbers
    @param k: Given the numbers of combinations
    @return: All the combinations of k numbers out of 1..n
    """
    def helper(self, n, pos, k, res, cur):
        if k == 0:
            res.append(cur[:])
            return
        if k < 0 or pos > n:
            return
        for i in range(pos, n + 1):
            cur.append(i)
            self.helper(n, i + 1, k - 1, res, cur)
            cur.pop()

    def combine(self, n, k):
        # write your code here
        res = []
        cur = []
        self.helper(n, 1, k, res, cur)
        return res