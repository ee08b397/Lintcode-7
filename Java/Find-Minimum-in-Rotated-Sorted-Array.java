public class Solution {
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    public int findMin(int[] num) {
        // write your code here
        //if (num == null || num.length == 0) return -1;
        int left = 0, right = num.length - 1;
        while (left + 1 < right) {
        	int mid = left + (right - left) / 2;
        	if (num[mid] < num[mid - 1] && num[mid] < num[mid + 1]) return num[mid];
        	if (num[mid] < num[right]) {
        		right = mid;
        	} else if(num[mid] > num[left]) {
        		left = mid;
        	}
        }
        return Math.min(num[left], num[right]);
    }
}
