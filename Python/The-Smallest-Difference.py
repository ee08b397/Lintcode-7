class Solution:
    # @param A, B: Two lists of integer
    # @return: An integer
    def smallestDifference(self, A, B):
        # write your code here
        A.sort()
        B.sort()
        mindiff = abs(A[0] - B[0])
        pa = 0
        pb = 0
        while pa < len(A) and pb < len(B):
            mindiff = min(mindiff, abs(A[pa] - B[pb]))
            if A[pa] < B[pb]:
                pa += 1
            else:
                pb += 1
        return mindiff