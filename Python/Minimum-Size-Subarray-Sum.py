class Solution:
     # @param nums: a list of integers
     # @param s: an integer
     # @return: an integer representing the minimum size of subarray
    def minimumSize(self, nums, s):
        # write your code here
        start = 0
        minlen = len(nums) + 1
        cur = 0
        for i in range(len(nums)):
            cur += nums[i]
            while cur >= s:
                minlen = min(minlen, i - start + 1)
                cur -= nums[start]
                start += 1
        if minlen > len(nums):
            return -1
        return minlen