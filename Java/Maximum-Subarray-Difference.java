public class Solution {
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    public int maxDiffSubArrays(ArrayList<Integer> nums) {
        // write your code
        int len = nums.size();
        int []leftmax = new int[len];
        int []leftmin = new int[len];
        int cur1 = -1, temp1 = Integer.MIN_VALUE, cur2 = 1, temp2 = Integer.MAX_VALUE;
        for (int i = 0; i < len; i ++) {
            cur1 = Math.max(nums.get(i), nums.get(i) + cur1);
            temp1 = Math.max(temp1, cur1);
            leftmax[i] = temp1;
            cur2 = Math.min(nums.get(i), nums.get(i) + cur2);
            temp2 = Math.min(temp2, cur2);
            leftmin[i] = temp2;
        }
        int res = 0;
        cur1 = -1;
        cur2 = 1;
        temp1 = Integer.MIN_VALUE;
        temp2 = Integer.MAX_VALUE;
        for (int i = len - 1; i > 0; i --) {
            cur1 = Math.max(nums.get(i), nums.get(i) + cur1);
            temp1 = Math.max(temp1, cur1);
            res = Math.max(res, Math.abs(temp1 - leftmin[i - 1]));
            cur2 = Math.min(nums.get(i), nums.get(i) + cur2);
            temp2 = Math.min(temp2, cur2);
            res = Math.max(res, Math.abs(temp2 - leftmax[i - 1]));
        }
        return res;
    }
}


