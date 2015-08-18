class Solution:
    # @param num: a rotated sorted array
    # @return: the minimum number in the array
    def findMin(self, num):
        # write your code here
        left = 0
        right = len(num) - 1
        while left + 1 < right:
            mid = (left + right) / 2
            if num[mid] < num[right]:
                right = mid
            else:
                left = mid;
        return min(num[left], num[right])