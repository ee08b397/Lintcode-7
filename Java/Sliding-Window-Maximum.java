public class Solution {
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    public ArrayList<Integer> maxSlidingWindow(int[] nums, int k) {
        // write your code here
        Deque<Integer> deque = new ArrayDeque<Integer>();
        ArrayList<Integer> res = new ArrayList<Integer>();
        if (nums == null || k == 0) return res;
        int len = nums.length;
        for (int i = 0; i < nums.length; i ++) {
            while (!deque.isEmpty() && deque.peek() < i - k + 1) {
                deque.poll();
            }
            while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i]) {
                deque.pollLast();
            }
            deque.offer(i);
            if (i >= k - 1) {
                res.add(nums[deque.peek()]);
            }
        }
        return res;
    }
}

