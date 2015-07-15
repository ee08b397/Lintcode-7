public class Solution {
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    public int reverseInteger(int n) {
        // Write your code here
        int res = 0, sign = 1;
        if (n < 0) {
            n = -n;
            sign = -1;
        }
        while (n != 0) {
            int temp = n % 10;
            n = n / 10;
            if (sign == 1 && ((res > Integer.MAX_VALUE / 10) ||
                    (res == Integer.MAX_VALUE / 10 && temp > Integer.MAX_VALUE % 10))) {
                return 0;
            }
            if (sign == -1 && (res > Integer.MAX_VALUE / 10 ||
                    (res == Integer.MAX_VALUE / 10 && temp > Integer.MAX_VALUE % 10 + 1))) {
                return 0;
            }
            res = res * 10 + temp;
        }
        return res * sign;
    }
}