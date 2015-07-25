public class Solution {
    /**
     * @param str: A string
     * @return An integer
     */
    public int atoi(String str) {
        // write your code here
        int sign = 1, res = 0;
        int index = 0;
        while (index < str.length() && str.charAt(index) == ' ') index ++;
        if (index < str.length() && str.charAt(index) == '-') {
            index ++;
            sign = -1;
        } else if (index < str.length() && str.charAt(index) == '+') {
            index ++;
        }
        while (index < str.length()) {
            if (str.charAt(index) < '0' || str.charAt(index) > '9') return res * sign;
            int temp = str.charAt(index++) - '0';
            if (sign == 1 && (res > Integer.MAX_VALUE / 10 ||
                    (res == Integer.MAX_VALUE / 10 && temp > Integer.MAX_VALUE % 10))) return Integer.MAX_VALUE;
            if (sign == - 1 && (res > Integer.MAX_VALUE / 10 ||
                    (res == Integer.MAX_VALUE / 10 && temp > Integer.MAX_VALUE % 10))) return Integer.MIN_VALUE;
            res = res * 10 + temp;
        }
        return res * sign;
    }
}