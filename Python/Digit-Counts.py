class Solution:
    # @param k & n  two integer
    # @return ans a integer
    def digitCounts(self, k, n):
        res = 0
        if k == 0 and n >= 0:
            res += 1
    	for i in range(1, n + 1):
            cur = i
            while cur != 0:
                if cur % 10 == k:
                    res += 1
                cur = cur / 10
        return res