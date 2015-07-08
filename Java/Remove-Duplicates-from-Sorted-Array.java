public class Solution {
    /**
     * @param A: a array of integers
     * @return : return an integer
     */
    public int removeDuplicates(int[] nums) {
        // write your code here
        int cur = -1;
        for (int i = 0; i < nums.length; i ++) {
        	if (cur == -1 || nums[i] != nums[cur]) {
        		nums[++cur] = nums[i]; 
        	}
        }
        return cur + 1;
    }
}
