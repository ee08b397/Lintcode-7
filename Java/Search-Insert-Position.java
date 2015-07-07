public class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
    // version 1: find the first position >= target
    public int searchInsert(int[] A, int target) {
        // write your code here
        if (A == null || A.length == 0) {
            return 0;
        }
        int left = 0, right = A.length - 1, mid;
        while (left + 1 < right) {
        	mid = left + (right - left) / 2;
        	if (A[mid] == target) return mid;
        	else if (A[mid] < target) left = mid;
        	else right = mid;
        }
        if (A[left] >= target) return left;
        else if (A[right] >= target) return right;
        else return right + 1;
    }
}
