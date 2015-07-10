public class Solution {
    /**
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    public int minSubArray(ArrayList<Integer> nums) {
        // write your code
        int minv = Integer.MAX_VALUE, cur = 0;
        for (int i = 0; i < nums.size(); i ++) {
            cur = Math.min(nums.get(i), cur + nums.get(i));
            minv = Math.min(minv, cur);
        }
        return minv;
    }
}

