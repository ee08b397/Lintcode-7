public class Solution {
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    public int[] plusOne(int[] digits) {
        // Write your code here
        int d = 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            int temp = digits[i] + d;
            digits[i] = temp % 10;
            d = temp / 10;
        }
        if (d == 1) {
            int [] res = new int[digits.length + 1];
            res[0] = 1;
            for (int i = 0; i < digits.length; i ++) {
                res[i + 1] = digits[i];
                return res;
            }
        }
        return digits;
    }
}
