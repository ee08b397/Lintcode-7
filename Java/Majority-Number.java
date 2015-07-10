public class Solution {
    /**
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    public int majorityNumber(ArrayList<Integer> nums) {
        // write your code
        int time = 1, cur = nums.get(0);
        for (int i = 1; i < nums.size(); i ++) {
            if (nums.get(i) == cur) {
                time ++;
            } else {
                time --;
                if (time == 0) {
                    time = 1;
                    cur = nums.get(i);
                }
            }
        }
        return cur;
    }
}

