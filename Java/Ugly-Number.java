class Solution {
    /**
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    public long kthPrimeNumber(int k) {
        // write your code here
        long []res = new long[k + 1];
        res[0] = 1;
        int i3 = 0, i5 = 0, i7 = 0;
        for (int i = 1; i <= k; i ++) {
            long x3 = res[i3] * 3, x5 = res[i5] * 5, x7 = res[i7] * 7;
            res[i] = Math.min(x3, Math.min(x5, x7));
            if (res[i] == x3) i3 ++;
            if (res[i] == x5) i5 ++;
            if (res[i] == x7) i7 ++;
        }
        return res[k];
    }
};
