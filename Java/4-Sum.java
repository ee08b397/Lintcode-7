public class Solution {
    /**
     * @param numbers : Give an array numbersbers of n integer
     * @param target : you need to find four elements that's sum of target
     * @return : Find all unique quadruplets in the array which gives the sum of
     *           zero.
     */
    public ArrayList<ArrayList<Integer>> fourSum(int[] numbers, int target) {
        //write your code here
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        Arrays.sort(numbers);
        for (int i = 0; i + 3 < numbers.length; i ++) {
            if (i != 0 && numbers[i] == numbers[i - 1]) continue;
            for (int j = i + 1; j + 2 < numbers.length; j ++) {
                if (j != i + 1 && numbers[j] == numbers[j - 1]) continue;
                int left = j + 1, right = numbers.length - 1;
                while (left < right) {
                    int temp = numbers[i] + numbers[j] + numbers[left] + numbers[right];
                    if (temp == target) {
                        ArrayList<Integer> cur = new ArrayList<Integer>();
                        cur.add(numbers[i]);
                        cur.add(numbers[j]);
                        cur.add(numbers[left]);
                        cur.add(numbers[right]);
                        res.add(cur);
                        int leftv = numbers[left++], rightv =  numbers[right --];
                        while (left <right && leftv == numbers[left]) left ++;
                        while (left <right && rightv == numbers[right]) right--;
                    } else if (temp < target) {
                        left ++;
                    } else {
                        right --;
                    }
                }
            }
        }
        return res;
    }
}