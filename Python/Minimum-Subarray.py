class Solution:
    """
    @param nums: a list of integers
    @return: A integer denote the sum of minimum subarray
    """
    def minSubArray(self, nums):
        # write your code here
        cur = 0
        minsub = nums[0]
        for item in nums:
            cur = min(item, item + cur)
            minsub = min(cur, minsub)
        return minsub