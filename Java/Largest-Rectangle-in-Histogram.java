public class Solution {
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    public int largestRectangleArea(int[] height) {
        // write your code here
        if (height == null || height.length == 0) return 0;
        Stack<Integer> stk = new Stack<Integer>();
        int maxArea = 0;
        for (int i = 0; i <= height.length; i ++) {
            int curt = (i == height.length) ? -1 : height[i];
            while (!stk.isEmpty() && curt <= height[stk.peek()]) {
                int h = height[stk.pop()];
                int w = stk.isEmpty() ? i : i - stk.peek() - 1;
                maxArea = Math.max(maxArea, h * w);
            }
            stk.push(i);
        }
        return maxArea;
    }
}