class Solution {
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    public int fibonacci(int n) {
        // write your code here
        if (n <= 2) return n - 1;
        int []arr = new int[n];
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i < n; i ++) {
        	arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n - 1];
    }
}


