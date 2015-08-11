class Solution:
    """
    @param A: a list of integers
    @return an integer
    """
    def removeDuplicates(self, A):
        # write your code here
        num = 0
        cur = 0
        pre = 0
        for item in A:
            if cur == 0 or item != pre:
                A[cur] = item
                cur += 1
                pre = item
                num = 1
            elif item == pre:
                if num < 2:
                    A[cur] = item
                    cur += 1
                    num += 1
        return cur