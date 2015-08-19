class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def helper(self, candidates, target, pos, res, cur):
        if target == 0:
            res.append(cur[:])
        for i in range(pos, len(candidates)):
            if candidates[i] > target:
                break
            cur.append(candidates[i])
            self.helper(candidates, target - candidates[i], i, res, cur)
            cur.pop()

    def combinationSum(self, candidates, target):
        # write your code here
        candidates.sort()
        res = []
        cur = []
        self.helper(candidates, target, 0, res, cur)
        return res