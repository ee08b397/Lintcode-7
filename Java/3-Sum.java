public class Solution {
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    public ArrayList<ArrayList<Integer>> threeSum(int[] numbers) {
        // write your code here
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        Arrays.sort(numbers);
        for (int i = 0; i + 2 < numbers.length; i ++) {
            if (i != 0 && numbers[i] == numbers[i - 1]) continue;
            int left = i + 1, right = numbers.length - 1;
            while (left < right) {
                int temp = numbers[i] + numbers[left] + numbers[right];
                if (temp == 0) {
                    ArrayList<Integer> cur = new ArrayList<Integer>();
                    cur.add(numbers[i]);
                    cur.add(numbers[left]);
                    cur.add(numbers[right]);
                    res.add(cur);
                    int leftv = numbers[left++], rightv = numbers[right--];
                    while (left < right && leftv == numbers[left]) left ++;
                    while (left < right && rightv == numbers[right]) right --;
                } else if(temp > 0) {
                    right --;
                } else {
                    left ++;
                }
            }
        }
        return res;
    }
}
