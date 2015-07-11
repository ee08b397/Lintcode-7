class Solution {
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    public void sortColors2(int[] colors, int k) {
        // write your code here
        int left = 0, right = colors.length;
        for (int i = k; i >= 2; i --) {
            left = 0;
            right --;
            while (left < right) {
                while (left < right && colors[left] < i) {
                    left ++;
                }
                while (left < right && colors[right] == i) {
                    right --;
                }
                if (left < right) {
                    int temp = colors[left];
                    colors[left] = colors[right];
                    colors[right] = temp;
                }
            }
        }
    }
}
