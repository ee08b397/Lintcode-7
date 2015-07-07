public class Solution {
    /**
     *@param A : an integer rotated sorted array
     *@param target :  an integer to be searched
     *return : an integer
     */
    public int search(int[] A, int target) {
        // write your code here
        if (A.length == 0) return -1;
        int left = 0, right = A.length - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) return mid;
            if (A[mid] < A[right]) {
                if (A[mid] < target && target <= A[right]) left = mid;
                else right = mid;
            } else if (A[mid] > A[left]) {
                if (A[mid] > target && target >= A[left]) right = mid;
                else left = mid;
            }
        }
        if (A[left] == target) return left;
        else if (A[right] == target) return right;
        else return -1;
    }
}