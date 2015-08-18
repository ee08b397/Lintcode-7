class Solution:
    """
    @param nums: A list of Integers.
    @return: A list of permutations.
    """
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

    def permuteUnique(self, nums):
        # write your code here
        if nums is None:
            return []
        nums.sort()
        res = []
        res.append(nums[:])
        while self.Permutate(nums):
            res.append(nums[:])
        return res
