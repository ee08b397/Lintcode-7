class Solution:
    """
    param A: A string
    param offset: Rotate string with offset.
    return: Rotated string.
    """
    def rotateString(self, A, offset):
        # write you code here
        size = len(A)
        if size == 0:
            return A
        offset = offset % size
        if offset == 0:
            return A
        str = ""
        str += A[size - offset:]
        str += A[0: size - offset]
        return str