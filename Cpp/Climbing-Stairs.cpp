class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        int *arr = new int[n+1];
        arr[0] = 0, arr[1] = 1, arr[2] = 2;
        for (int i = 3; i <= n; i ++) {
          arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n];
    }
};
