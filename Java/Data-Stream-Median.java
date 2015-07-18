class Solution {
    /**
     * @param nums: A list of integers.
     * @return: the median of numbers
     */
    public int[] medianII(int[] nums) {
        // write your code here
        PriorityQueue<Integer> maxheap = new PriorityQueue<Integer>(nums.length / 2 + 1,Collections.reverseOrder());
        PriorityQueue<Integer> minheap = new PriorityQueue<Integer>();
        int len = nums.length;
        int[] res = new int[len];
        for (int i = 0; i < len; i ++) {
            if (minheap.size() == maxheap.size()) {
                if (minheap.isEmpty()) {
                    minheap.add(nums[i]);
                } else {
                    if (nums[i] < maxheap.peek()) {
                        int temp = maxheap.poll();
                        maxheap.add(nums[i]);
                        minheap.add(temp);
                    } else {
                        minheap.add(nums[i]);
                    }
                }
            } else {
                if (nums[i] <= minheap.peek()) {
                    maxheap.add(nums[i]);
                } else {
                    int temp = minheap.poll();
                    minheap.add(nums[i]);
                    maxheap.add(temp);
                }
            }
            if (i % 2 == 0) {
                res[i] = minheap.peek();
            } else {
                res[i] = maxheap.peek();
            }
        }
        return res;
    }
}