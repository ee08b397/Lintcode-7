class Solution:
    """
    @param candidates: Given the candidate numbers
    @param target: Given the target number
    @return: All the combinations that sum to target
    """
    def helper(self, candidates, target, pos, res, cur):
        if target == 0:
            res.append(cur[:])
        pre = -1
        sign = -1
        for i in range(pos, len(candidates)):
            if candidates[i] > target:
                break
            if sign == 1 and pre == candidates[i]:
                continue
            sign = 1
            pre = candidates[i]
            cur.append(candidates[i])
            self.helper(candidates, target - candidates[i], i + 1, res, cur)
            cur.pop()
    def combinationSum2(self, candidates, target):
        # write your code here
        candidates.sort()
        res = []
        cur = []
        self.helper(candidates, target, 0, res, cur)
        return res