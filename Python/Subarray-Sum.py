class Solution:
    """
    @param nums: A list of integers
    @return: A list of integers includes the index of the first number
             and the index of the last number
    """
    def subarraySum(self, nums):
        # write your code here
        dict = {}
        dict[0] = -1
        res = []
        cur = 0
        for i in range(len(nums)):
            cur += nums[i]
            if cur in dict:
                res.append(dict[cur] + 1)
                res.append(i)
                return res
            dict[cur] = i
        return res