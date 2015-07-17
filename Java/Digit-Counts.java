class Solution {
    /*
     * param k : As description.
     * param n : As description.
     * return: An integer denote the count of digit k in 1..n
     */
    public int digitCounts(int k, int n) {
        // write your code here
        int res = 0;
        for (int i = 0; i <= n; i ++) {
            int cur = i;
            do {
                if (cur % 10 == k) res ++;
                cur = cur / 10;
            } while (cur > 0);
        }
        return res;
    }
};
