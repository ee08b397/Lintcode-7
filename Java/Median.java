public class Solution {
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    public int FindKth(int[] nums, int start, int end, int k) {
        if (start == end) return nums[start];
        int left = start + 1, right = end;
        while (left <= right) {
            while (left <= right && nums[left] < nums[start]) left ++;
            while (left <= right && nums[right] >= nums[start]) right --;
            if (left < right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left ++;
                right --;
            }
        }
        int temp = nums[start];
        nums[start] = nums[right];
        nums[right] = temp;
        if (right - start + 1 == k) return nums[right];
        else if (right - start + 1 < k) return FindKth(nums, right + 1, end, k - (right - start + 1));
        else return FindKth(nums, start, right - 1, k);
    }
    public int median(int[] nums) {
        // write your code here
        int len = nums.length;
        if (len % 2 == 0) return FindKth(nums, 0, len - 1, len / 2);
        else return FindKth(nums, 0, len - 1, len / 2 + 1);
    }
}

