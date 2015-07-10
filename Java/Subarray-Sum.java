public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    public ArrayList<Integer> subarraySum(int[] nums) {
        // write your code here
        HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
        ArrayList<Integer> res = new ArrayList<Integer>();
        hash.put(0, -1);
        int sum = 0;
        for (int i = 0; i < nums.length; i ++) {
            sum += nums[i];
            if (hash.containsKey(sum)) {
                res.add(hash.get(sum) + 1);
                res.add(i);
                return res;
            } else {
                hash.put(sum, i);
            }
        }
        return res;
    }
}
