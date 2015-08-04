class Solution:
    # @param nums: a list of integers
    # @return: nothing
    def partitionArray(self, nums):
        # write your code here
        left = 0
        right = len(nums) - 1
        while left < right:
            while left < right and nums[left] & 1 == 1:
                left += 1
            while left < right and nums[right] & 1 == 0:
                right -= 1
            if left < right:
                temp = nums[left]
                nums[left] = nums[right]
                nums[right] = temp
