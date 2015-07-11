public class Solution {
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target : An integer
     * @return : return the sum of the three integers, the sum closest target.
     */
    public int threeSumClosest(int[] numbers ,int target) {
        // write your code here
        int ClosestVal = -1, Minv = Integer.MAX_VALUE;
        Arrays.sort(numbers);
        for (int i = 0; i + 2 < numbers.length; i ++) {
            int left = i + 1, right = numbers.length - 1;
            while (left < right) {
                int temp = numbers[left] + numbers[right] + numbers[i];
                if (temp == target) return temp;
                if (Math.abs(temp - target) < Minv) {
                    ClosestVal = temp;
                    Minv = Math.abs(temp - target);
                }
                if (temp < target) {
                    left ++;
                } else {
                    right --;
                }
            }
        }
        return ClosestVal;
    }
}