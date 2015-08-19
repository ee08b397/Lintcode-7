class Solution:
    # @param heights: a list of integers
    # @return: a integer
    def trapRainWater(self, heights):
        # write your code here
        if len(heights) == 0:
            return 0
        maxh = heights[0]
        cur = 0
        for i in range(len(heights)):
            if heights[i] > maxh:
                maxh = heights[i]
                cur = i
        res = 0
        pre = heights[0]
        for i in range(cur):
            res += max(0, pre - heights[i])
            pre = max(pre, heights[i])
        pre = heights[-1]
        index = len(heights) - 1
        while index > cur:
            res += max(0, pre - heights[index])
            pre = max(pre, heights[index])
            index -= 1
        return res
