class Solution:
    """
    @param x: An integer
    @return: The sqrt of x
    """
    def sqrt(self, x):
        # write your code here
        if x <= 1:
            return x
        low = 1
        high = x
        while low <= high:
            mid = low + (high - low) / 2
            if mid * mid == x:
                return mid
            elif mid * mid < x and (mid + 1) * (mid + 1) > x:
                return mid
            elif mid * mid < x:
                low = mid + 1
            elif mid * mid > x:
                high = mid - 1
        return low