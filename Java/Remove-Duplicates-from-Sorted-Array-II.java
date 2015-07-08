public class Solution {
    /**
     * @param A: a array of integers
     * @return : return an integer
     */
    public int removeDuplicates(int[] nums) {
        // write your code here
        int cur = -1, time = 1;
        for (int i = 0; i < nums.length; i ++) {
        	if (cur == -1 || nums[i] != nums[cur]) {
        		time = 1;
        		nums[++cur] = nums[i];
        	} else if (nums[i] == nums[cur]) {
        		if (time++ == 1) {
        			nums[++cur] = nums[i];
        		}
        	}
        }
        return cur + 1;
    }
}
