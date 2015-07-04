public class Solution {
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    public int longestIncreasingSubsequence(int[] nums) {
        // write your code here
        int len = nums.length;
        int []dp = new int[len];
        for (int i = 0; i < len; i ++) {
        	dp[i] = 1;
        	for (int j = 0; j < i; j ++) {
        		if (nums[i] >= nums[j]) {
        			dp[i] = Math.max(dp[i], dp[j] + 1);
        		}
        	}
        }
        int maxlen = 0;
        for (int i = 0; i < len; i ++) {
        	maxlen = Math.max(maxlen, dp[i]);
        }
        return maxlen;
    }
}

