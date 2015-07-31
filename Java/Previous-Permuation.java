public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */
    public ArrayList<Integer> previousPermuation(ArrayList<Integer> nums) {
        int peakInd = nums.size() - 1;
        while (peakInd > 0 && nums.get(peakInd-1) <= nums.get(peakInd)) {
            peakInd--;
        }
        peakInd--;
        if (peakInd >= 0) {
            int swapInd = peakInd + 1;
            while (swapInd < nums.size() && nums.get(swapInd) < nums.get(peakInd)) {
                swapInd++;
            }
            swapInd--;
            int tmp = nums.get(swapInd);
            nums.set(swapInd, nums.get(peakInd));
            nums.set(peakInd, tmp);
        }
        int left = peakInd + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int tmp = nums.get(left);
            nums.set(left, nums.get(right));
            nums.set(right, tmp);
            left++;
            right--;
        }
        return nums;
    }
}

