public class Solution {
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    public int maxTwoSubArrays(ArrayList<Integer> nums) {
        // write your code
        int cur = -1, maxv = Integer.MIN_VALUE;
        HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.size(); i ++) {
            cur = Math.max(nums.get(i), cur + nums.get(i));
            maxv = Math.max(cur, maxv);
            hash.put(i, maxv);
        }
        cur = -1;
        maxv = Integer.MIN_VALUE;
        int res = maxv;
        for (int i = nums.size() - 1; i > 0; i --) {
            cur = Math.max(nums.get(i), cur + nums.get(i));
            maxv = Math.max(cur, maxv);
            res = Math.max(res, maxv + hash.get(i - 1));
        }
        return res;
    }
}