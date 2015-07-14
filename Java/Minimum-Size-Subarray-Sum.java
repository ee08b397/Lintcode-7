public class Solution {
    /**
     * @param nums: an array of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    public int minimumSize(int[] nums, int s) {
        // write your code here
        int minsize = nums.length + 1, cur = 0, left = 0;
        for (int i = 0; i < nums.length; i ++) {
            cur += nums[i];
            while (left <= i && cur >= s) {
                minsize = Math.min(minsize, i - left + 1);
                cur -= nums[left];
                left ++;
            }
        }
        if (minsize > nums.length) return -1;
        return minsize;
    }
}