public class Solution {
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    public int sumSubArray(ArrayList<Integer> nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i ++) {
            res += nums.get(i);
        }
        return res;
    }
    public int maxSubArray(ArrayList<Integer> nums, int k) {
        // write your code
        if (k == 0) return 0;
        if (k >= nums.size()) return sumSubArray(nums);
        int n = nums.size();
        int[][] f = new int[n + 1][n + 1];
        int[][] p = new int[n + 1][n + 1];
        int sum;
        for (int i = 1; i <= k; i ++) {
            sum = Integer.MIN_VALUE;
            f[i][i] = f[i - 1][i - 1] + nums.get(i - 1);
            p[i][i] = f[i][i];
            sum = f[i][i];
            for (int j = i + 1; j <= n; j ++) {
                f[i][j] = Math.max(p[i - 1][j - 1], f[i][j - 1]) + nums.get(j - 1);
                sum = Math.max(sum, f[i][j]);
                p[i][j] = sum;
            }
        }
        int res = Integer.MIN_VALUE;
        for (int i = k; i <= n; i ++) {
            res = Math.max(res, f[k][i]);
        }
        return res;
    }
}
