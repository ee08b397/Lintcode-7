class Solution:
    # @param heights: a list of integers
    # @return: an integer
    def maxArea(self, heights):
        # write your code here
        maxarea = 0
    	left = 0
        right = len(heights) - 1
        while left < right:
            maxarea = max(maxarea, min(heights[left], heights[right]) * (right - left))
            if heights[left] < heights[right]:
                left += 1
            else:
                right -= 1
        return maxarea