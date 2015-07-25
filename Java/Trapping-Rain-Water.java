public class Solution {
    /**
     * @param heights: an array of integers
     * @return: a integer
     */
    public int trapRainWater(int[] heights) {
        // write your code here
        int maxh = -1, index = 0;
        for (int i = 0; i < heights.length; i ++) {
            if (heights[i] > maxh) {
                index = i;
                maxh = heights[i];
            }
        }
        int res = 0, lefth = -1, righth = -1;
        for (int i = 0; i < index; i ++) {
            if (heights[i] >= lefth) {
                lefth = heights[i];
            } else {
                res += (lefth - heights[i]);
            }
        }
        for (int i = heights.length - 1; i > index; i --) {
            if (heights[i] >= righth) {
                righth = heights[i];
            } else {
                res += (righth - heights[i]);
            }
        }
        return res;
    }
}