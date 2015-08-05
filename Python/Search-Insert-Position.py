class Solution:
    """
    @param A : a list of integers
    @param target : an integer to be inserted
    @return : an integer
    """
    def searchInsert(self, A, target):
        # write your code here
        if A is None or len(A) == 0:
            return 0
        left = 0
        right = len(A) - 1
        while left + 1 < right:
            mid = left + (right - left) / 2
            if A[mid] > target:
                right = mid
            else:
                left = mid
        if A[left] >= target:
            return left
        elif A[right] >= target:
            return right
        return len(A)