public class Solution {
    /**
     * @param pages: an array of integers
     * @param k: an integer
     * @return: an integer
     */
    // time complexity: O(NlogM)(M = sum(pages[i]))
    public boolean isok(int[] pages, int num, int k) {
        int count = 0, cur = 0;
        for (int i = 0; i < pages.length; i ++) {
            if (cur + pages[i] > num) {
                count ++;
                cur = pages[i];
            } else {
                cur += pages[i];
            }
        }
        count ++;
        if (count <= k) return true;
        return false;
    }
    public int copyBooks(int[] pages, int k) {
        // write your code here
        int tot = 0, maxt = Integer.MIN_VALUE;
        for (int i = 0; i < pages.length; i ++) {
            tot += pages[i];
            maxt = Math.max(maxt, pages[i]);
        }
        int left = 0, right = tot, res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isok(pages, mid, k) && mid >= maxt) {
                right = mid - 1;
                res = mid;
            } else {
                left = mid + 1;
            }
        }
        return Math.max(res, maxt);
    }
}

public class Solution {
    /**
     * @param pages: an array of integers
     * @param k: an integer
     * @return: an integer
     */
    // time complexity O(N^2*K)
    public int copyBooks(int[] pages, int k) {
        // write your code here
        int len = pages.length;
        int[][] dp = new int[k+1][len];//dp[i][j] 代表前i本书由j个工作者完成需要的最小时间
        for (int i = 0; i <= k; i ++) {
            for (int j = 0; j < len; j ++) dp[i][j] = Integer.MAX_VALUE;
        }
        k = Math.min(len, k);
        for (int i = 1; i < len; i ++) {
            pages[i] += pages[i - 1];
        }
        for (int i = 1; i <= k; i ++) {
            for (int j = 0; j < len; j ++) {
                if (i == 1 || j == 0) {
                    dp[i][j] = pages[j];
                } else {
                    for (int r = j - 1; r >= 0; r --) {
                        int cur = Math.max(dp[i - 1][r], pages[j] - pages[r]);
                        dp[i][j] = Math.min(dp[i][j], cur);
                    }
                }
            }
        }
        return dp[k][len - 1];
    }
}