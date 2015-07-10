class Solution {
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    public int fastPower(int a, int b, int n) {
        // write your code here
        if (n == 0) return 1 % b;
        if (n == 1) return a % b;
        long temp = fastPower(a, b, n / 2);
        long res = ((temp % b) * (temp % b)) % b;
        if (n % 2 != 0) {
            res = (res * (a % b)) % b;
        }
        return (int)res;
    }
};
