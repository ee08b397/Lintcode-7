public class Solution {
    /**
     * @param nums: A list of integers
     * @return: The majority number that occurs more than 1/3
     */
    public int majorityNumber(ArrayList<Integer> nums) {
        // write your code
        int cur1 = 0, num1 = 0, cur2 = 0, num2 = 0;
        for (int i = 0; i < nums.size(); i ++) {
            int cnt = nums.get(i);
            if (num1 != 0 && cur1 == cnt) {
                num1 ++;
            } else if (num2 != 0 && cur2 == cnt) {
                num2 ++;
            } else if (num1 == 0) {
                cur1 = cnt;
                num1 = 1;
            } else if (num2 == 0) {
                cur2 = cnt;
                num2 = 1;
            } else {
                num1 --;
                num2 --;
            }
        }
        num1 = 0; num2 = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums.get(i) == cur1) num1 ++;
            else if (nums.get(i) == cur2) num2 ++;
        }
        if (num1 > num2) return cur1;
        else return cur2;
    }
}
