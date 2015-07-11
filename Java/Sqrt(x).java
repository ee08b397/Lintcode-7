class Solution {
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    public int sqrt(int x) {
        // write your code here
        long low = 0, high = x, cnt = x;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            if (mid * mid > cnt) high = mid - 1;
            else low = mid + 1;
        }
        return (int) high;
    }
}
