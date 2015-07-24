class Solution {
    /**
     * @param nums: an array of integers
     * @return: the maximum difference
     */
    public int maximumGap(int[] nums) {
        // write your code here
        if (nums.length < 2) return 0;
        int maxv = Integer.MIN_VALUE, minv = Integer.MAX_VALUE, len = nums.length;
        for (int i = 0; i < nums.length; i ++) {
            maxv = Math.max(maxv, nums[i]);
            minv = Math.min(minv, nums[i]);
        }
        int bucketval = (maxv - minv) / len + 1;
        ArrayList<ArrayList<Integer>> bucket = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < (maxv - minv) / bucketval + 1; i ++) {
            bucket.add(new ArrayList<Integer>());
        }
        for (int i = 0; i < nums.length; i ++) {
            int index = (nums[i] - minv) / bucketval;
            bucket.get(index).add(nums[i]);
        }
        int maxgap = 0, prev = minv;
        for (int i = 0; i < bucket.size(); i ++) {
            if (bucket.get(i).isEmpty()) continue;
            int minp = bucket.get(i).get(0), maxp = bucket.get(i).get(0);
            for (int j = 1; j < bucket.get(i).size(); j ++) {
                minp = Math.min(bucket.get(i).get(j), minp);
                maxp = Math.max(bucket.get(i).get(j), maxp);
            }
            maxgap = Math.max(maxgap, minp - prev);
            prev = maxp;
        }
        return maxgap;
    }
}