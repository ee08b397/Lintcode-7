class Solution:
    """
    @param S: A set of numbers.
    @return: A list of lists. All valid subsets.
    """
    def helper(self, S, pos, res, cur):
        res.append(cur[:])
        pre = -1
        sign = -1
        for i in xrange(pos, len(S)):
            if sign == -1 or (sign == 1 and S[i] != pre):
                pre = S[i]
                sign = 1
                cur.append(S[i])
                self.helper(S, i + 1, res, cur)
                cur.pop()

    def subsetsWithDup(self, S):
        # write your code here
        S.sort()
        res = []
        cur = []
        self.helper(S, 0, res, cur)
        return res