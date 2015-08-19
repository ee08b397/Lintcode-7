class Solution:
    """
    @param S: The set of numbers.
    @return: A list of lists. See example.
    """
    def helper(self, S, pos, res, cur):
        res.append(cur[:])
        for i in xrange(pos, len(S)):
            cur.append(S[i])
            self.helper(S, i + 1, res, cur)
            cur.pop()

    def subsets(self, S):
        # write your code here
        S.sort()
        res = []
        cur = []
        self.helper(S, 0, res, cur)
        return res