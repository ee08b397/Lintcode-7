public class Solution {
    /*
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    public void swap(char[] A, int left, int right) {
        char temp;
        while (left < right) {
            temp = A[left];
            A[left] = A[right];
            A[right] = temp;
            left ++;
            right --;
        }
    }
    public char[] rotateString(char[] A, int offset) {
        // wirte your code here
        int len = A.length;
        if (A == null || len == 0) return A;
        if (offset % len == 0) return A;
        offset = offset % len;
        swap(A, 0, len - offset - 1);
        swap(A, len - offset, len - 1);
        swap(A, 0, len - 1);
        return A;
    }
};