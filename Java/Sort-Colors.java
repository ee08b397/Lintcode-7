import java.util.*;

class Solution {
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    public void sortColors(int[] nums) {
        // write your code here
        int left = 0, right = nums.length - 1;
        while (left < right) {
            while (left < right && nums[left] < 2) {
                left ++;
            }
            while (left < right && nums[right] == 2) {
                right --;
            }
            if (left < right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }
        left = 0;
        right --;
        while (left < right) {
            while (left < right && nums[left]  == 0) {
                left ++;
            }
            while (left < right && nums[right] == 1) {
                right --;
            }
            if (left < right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }
    }
}
