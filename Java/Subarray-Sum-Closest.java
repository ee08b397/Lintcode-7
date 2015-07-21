public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    public ArrayList<Integer> subarraySumClosest(int[] nums) {
        // write your code here
        HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
        ArrayList<Integer> res = new ArrayList<Integer>();
        if (nums == null || nums.length <= 0) return res;
        if (nums.length == 1) {
            res.add(0);
            res.add(0);
            return res;
        }
        int[] sum = new int[nums.length];
        int cur = 0;
        hash.put(0, -1);
        for (int i = 0; i < nums.length; i ++) {
            cur += nums[i];
            if (hash.containsKey(cur)) {
                res.add(hash.get(cur) + 1);
                res.add(i);
                return res;
            }
            hash.put(cur, i);
            sum[i] = cur;
        }
        Arrays.sort(sum);
        int minGap = Integer.MAX_VALUE, pa = 0;
        for (int i = 0; i + 1 < sum.length; i ++) {
            if (Math.abs(sum[i] - sum[i + 1]) < minGap) {
                pa = i;
                minGap = Math.abs(sum[i] - sum[i + 1]);
            }
        }
        int ps = hash.get(sum[pa]), pe = hash.get(sum[pa + 1]);
        if (ps > pe) {
            int temp = ps;
            ps = pe;
            pe = temp;
        }
        res.add(ps + 1);
        res.add(pe);
        return  res;
    }
}
