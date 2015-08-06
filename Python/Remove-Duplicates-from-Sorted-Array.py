class Solution:
    """
    @param A: a list of integers
    @return an integer
    """
    def removeDuplicates(self, A):
        # write your code here
        cur = 0
        for i in A:
            if cur == 0 or i != A[cur - 1]:
                A[cur] = i
                cur += 1
        return cur
