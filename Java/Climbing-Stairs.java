public class Solution {
    /**
     * @param n: An integer
     * @return: An integer
     */
    public int climbStairs(int n) {
        // write your code here
        if (n <= 3) return n;
        int[] arr = new int[n];
        arr[0] = 1;
        arr[1] = 2;
        for (int i = 2; i < n; i ++) {
        	arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n - 1];
    }
}
