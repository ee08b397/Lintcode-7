public class Solution {
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    public int findMin(int[] num) {
        // write your code here
        int minval = num[0];
        for (int i = 1; i < num.length; i ++) {
        	minval = Math.min(num[i], minval);
        }
        return minval;
    }
}
