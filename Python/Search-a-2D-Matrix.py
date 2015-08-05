class Solution:
    """
    @param matrix, a list of lists of integers
    @param target, an integer
    @return a boolean, indicate whether matrix contains target
    """
    def searchMatrix(self, matrix, target):
        # write your code here
        lenx = len(matrix)
        if lenx == 0 or matrix is None:
            return False
        leny = len(matrix[0])
        left = 0
        right = lenx * leny - 1
        while left <= right:
            mid = left + (right - left) / 2
            x = mid / leny
            y = mid % leny
            if matrix[x][y] == target:
                return True
            elif matrix[x][y] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False
