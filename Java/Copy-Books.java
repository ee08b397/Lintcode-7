public class Solution {
    /**
     * @param pages: an array of integers
     * @param k: an integer
     * @return: an integer
     */
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
