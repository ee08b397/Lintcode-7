public class Solution {
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    public boolean CanCut(int[] L, int k, int cur) {
        int res = 0;
        for (int i = 0; i < L.length; i ++) {
            res += L[i] / cur;
        }
        if (res >= k) return true;
        return false;
    }
    public int woodCut(int[] L, int k) {
        // write your code here
        int left = 1, right = Integer.MAX_VALUE, res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (CanCut(L, k, mid)) {
                left = mid + 1;
                res = mid;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
}