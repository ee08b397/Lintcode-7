class Solution {
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    public static int bitSwapRequired(int a, int b) {
        // write your code here
        int cnt = a ^ b, res = 0;
        while (cnt != 0) {
            cnt = cnt & (cnt - 1);
            res ++;
        }
        return res;
    }
};