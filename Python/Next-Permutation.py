class Solution:
    # @param nums: a list of integer
    # @return: return nothing (void), do not return anything, modify nums in-place instead
    def reverse(self, nums, left, right):
        while left < right:
            temp = nums[left]
            nums[left] = nums[right]
            nums[right] = temp
            left += 1
            right -= 1

    def Permutate(self, nums):
        if len(nums) <= 1:
            return False
        pa = len(nums) - 1
        pb = pa - 1
        while pb >= 0 and nums[pa] <= nums[pb]:
            pa -= 1
            pb -= 1
        if pb < 0:
            return False
        pc = len(nums) - 1
        while nums[pc] <= nums[pb]:
            pc -= 1
        temp = nums[pb]
        nums[pb] = nums[pc]
        nums[pc] = temp
        self.reverse(nums, pa, len(nums) - 1)
        return True

    def nextPermutation(self, nums):
        # write your code here
        if self.Permutate(nums):
            return nums
        self.reverse(nums, 0, len(nums) - 1)
        return nums
