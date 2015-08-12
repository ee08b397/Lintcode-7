class Solution:
    """
    @param nums: A list of integers
    @return: An integer denote the sum of maximum subarray
    """
    def maxSubArray(self, nums):
        # write your code here
        cur = 0
        maxsub = nums[0]
        for item in nums:
            cur = max(item, item + cur)
            maxsub = max(cur, maxsub)
        return maxsub