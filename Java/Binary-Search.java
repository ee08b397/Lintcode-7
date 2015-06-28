class Solution {
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    public int binarySearch(int[] nums, int target) {
        //write your code here
        int left = 0, right = nums.length, mid;
        while (left + 1 < right) {
        	mid = left + (right - left) / 2;
        	if (nums[mid] == target) {
        		right = mid;
        	} else if (nums[mid] > target) {
        		right = mid;
        	} else {
        		left = mid;
        	}
        }
        if (nums[left] == target) return left;
        else if(nums[right] == target) return right;
        return -1;
    }
}
