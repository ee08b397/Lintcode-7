class Solution:
    # @param k & A a integer and an array
    # @return ans a integer
    def FindKth(self, k, A, start, end):
        if start == end:
            return A[start]
        left = start + 1
        right = end
        while left <= right:
            while left <= right and A[right] >= A[start]:
                right -= 1
            while left <= right and A[left] < A[start]:
                left += 1
            if left < right:
                temp = A[left]
                A[left] = A[right]
                A[right] = temp
        temp = A[start]
        A[start] = A[right]
        A[right] = temp
        if right - start + 1 == k:
            return A[right]
        elif right - start + 1 < k:
            return self.FindKth(k - (right - start + 1), A, right + 1, end)
        else:
            return self.FindKth(k, A, start, right - 1)
    def kthLargestElement(self, k, A):
        return self.FindKth(len(A) - k + 1, A, 0, len(A) - 1)