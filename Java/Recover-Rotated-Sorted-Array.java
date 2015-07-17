public class Solution {
    /**
     * @param nums: The rotated sorted array
     * @return: void
     */
    public void swap(ArrayList<Integer> nums, int left, int right) {
        int temp;
        while (left < right) {
            temp = nums.get(left);
            nums.set(left, nums.get(right));
            nums.set(right, temp);
            left ++;
            right --;
        }
    }
    public void recoverRotatedSortedArray(ArrayList<Integer> nums) {
        // write your code
        int cur = -1;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums.get(i) < nums.get(i - 1)) {
                cur = i;
                break;
            }
        }
        if (cur == -1) return;
        swap(nums, 0, cur - 1);
        swap(nums, cur, nums.size() - 1);
        swap(nums, 0, nums.size() - 1);
    }
}