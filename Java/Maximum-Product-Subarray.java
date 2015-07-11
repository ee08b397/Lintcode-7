public class Solution {
    /**
     * @param nums: an array of integers
     * @return: an integer
     */
    public int maxProduct(int[] nums) {
        // write your code here
        int cur = nums[0], maxv = nums[0], minv = nums[0];
        int x, y, z;
        for (int i = 1; i < nums.length; i ++) {
            x = nums[i] * maxv;
            y = nums[i] * minv;
            z = nums[i];
            minv = Math.min(x, Math.min(y, z));
            maxv = Math.max(x, Math.max(y, z));
            if (maxv > cur) cur = maxv;
        }
        return cur;
    }
}