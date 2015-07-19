public class Solution {
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        // write your code here
        if (triangle == null || triangle.size() <= 0) return 0;
        int len = triangle.size();
        int []dp = new int[len];
        for (int i = 0; i < len; i ++) {
            dp[i] = triangle.get(len - 1).get(i);
        }
        for (int i = len - 2; i >= 0; i --) {
            for (int j = 0; j <= i; j ++) {
                dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
            }
        }
        return dp[0];
    }
}