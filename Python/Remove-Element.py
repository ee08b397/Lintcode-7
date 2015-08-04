class Solution:
    """
    @param A: A list of integers
    @param elem: An integer
    @return: The new length after remove
    """
    def removeElement(self, A, elem):
        # write your code here
        cur = 0
        for i in A:
            if i != elem:
                A[cur] = i
                cur += 1
        return cur