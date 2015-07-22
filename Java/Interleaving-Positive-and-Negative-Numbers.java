class Solution {
    /**
     * @param A: An integer array.
     * @return: void
     */
    public void rerange(int[] A) {
        // write your code here
        int left = 0, right = A.length - 1, pos = 0, neg = 0;
        while (left < right) {
            while (left < right && A[left] < 0) {
                left ++;
                neg ++; // attention
            }
            while (left < right && A[right] > 0) {
                right --;
            }
            if (left < right) {
                int temp = A[left];
                A[left] = A[right];
                A[right] = temp;
            }
        }
        left = 0;right = A.length - 1;
        pos = A.length - neg;
        if (neg < pos) {
            right --;
        } else if (neg > pos) {
            left ++;
        }
        while (left < right) {
            int temp = A[left];
            A[left] = A[right];
            A[right] = temp;
            left += 2;
            right -= 2;
        }
    }
}
