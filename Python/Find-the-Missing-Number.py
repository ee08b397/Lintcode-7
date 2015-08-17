class Solution:
    # @param nums: a list of integers
    # @return: an integer
    def findMissing(self, nums):
        # write your code here
        N = len(nums)
        for i in xrange(N):
            while nums[i] < N and nums[i] != i:
                temp = nums[nums[i]]
                nums[nums[i]] = nums[i]
                nums[i] = temp
        for i in xrange(N):
            if nums[i] != i:
                return i
        return N
