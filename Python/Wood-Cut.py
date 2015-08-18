class Solution:
    """
    @param L: Given n pieces of wood with length L[i]
    @param k: An integer
    return: The maximum length of the small pieces.
    """
    def canCut(self, L, k, length):
        if length == 0:
            return True
        res = 0
        for item in L:
            res += item / length
        return res >= k
    def woodCut(self, L, k):
        # write your code here
        if L is None or len(L) == 0:
            return 0
        maxlen = L[0]
        for item in L:
            maxlen = max(maxlen, item)
        low = 0
        high = maxlen
        cur = 0
        while low <= high:
            mid = (low + high) / 2
            if self.canCut(L, k, mid):
                cur = max(cur, mid)
                low = mid + 1
            else:
                high = mid - 1
        return cur