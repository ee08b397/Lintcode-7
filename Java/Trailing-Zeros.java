class Solution {
    /*
     * param n: As desciption
     * return: An integer, denote the number of trailing zeros in n!
     */
    public long trailingZeros(long n) {
        // write your code here
        long num = 0;
        while (n != 0) {
            num += n / 5;
            n = n / 5;
        }
        return num;
    }
};

