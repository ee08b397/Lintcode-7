class Solution:
    """
    @param nums: A list of integers
    @return: The majority number
    """
    def majorityNumber(self, nums):
        # write your code here
        cur = -1
        times = 0
        for i in nums:
            if times == 0:
                times = 1
                cur = i
            elif i == cur:
                times += 1
            elif i != cur:
                times -= 1
        return cur