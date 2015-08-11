class Solution:
    """
    @param nums: The rotated sorted array
    @return: nothing
    """
    def reverse(self, nums, left, right):
        while left < right:
            temp = nums[left]
            nums[left] = nums[right]
            nums[right] = temp
            left += 1
            right -= 1

    def recoverRotatedSortedArray(self, nums):
        # write your code here
        pos = -1
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                pos = i
                break
        if (pos == -1): return
        ##reversed(nums, 0, pos)
        self.reverse(nums, 0, pos)
        self.reverse(nums, pos + 1, len(nums) - 1)
        self.reverse(nums, 0, len(nums) - 1)