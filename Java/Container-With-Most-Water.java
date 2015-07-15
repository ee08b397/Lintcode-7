public class Solution {
    /**
     * @param heights: an array of integers
     * @return: an integer
     */
    public int maxArea(int[] heights) {
        // write your code here
        int maxV = 0, left = 0, right = heights.length - 1;
        while (left < right) {
            maxV = Math.max(maxV, (right - left) * (Math.min(heights[left], heights[right])));
            if (heights[left] <= heights[right]) left ++;
            else right --;
        }
        return maxV;
    }
}
