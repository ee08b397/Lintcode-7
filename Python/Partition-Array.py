class Solution:
    """
    @param nums: The integer array you should partition
    @param k: As description
    @return: The index after partition
    """
    def partitionArray(self, nums, k):
        # write your code here
        # you should partition the nums by k
        # and return the partition index as description
        left = 0
        right = len(nums) - 1
        while left < right:
            while left < right and nums[left] < k:
                left += 1
            while left < right and nums[right] >= k:
                right -= 1
            if left < right:
                temp = nums[left]
                nums[left] = nums[right]
                nums[right] = temp
        for i in range(len(nums)):
            if nums[i] >= k:
                return i
        return len(nums)