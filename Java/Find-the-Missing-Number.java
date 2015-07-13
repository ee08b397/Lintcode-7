public class Solution {
    /**
     * @param nums: an array of integers
     * @return: an integer
     */
    public int findMissing(int[] nums) {
        // write your code here
        int len = nums.length;
        int cur = 0;
        while (cur < len) {
            int cnt = nums[cur];
            if (cnt < len && nums[cnt] != cnt) {
                int temp = nums[cur];
                nums[cur] = nums[cnt];
                nums[cnt] = temp;
            } else {
                cur++;
            }
        }
        for (int i = 0; i < len; i ++) {
            if (nums[i] != i) return i;
        }
        return len;
    }
}
