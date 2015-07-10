public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    public int maxSubArray(ArrayList<Integer> nums) {
        // write your code
        int maxv = Integer.MIN_VALUE, cur = 0;
        for (int i = 0; i < nums.size(); i ++) {
            cur = Math.max(cur + nums.get(i), nums.get(i));
            maxv = Math.max(maxv, cur);
        }
        return maxv;
    }
}
