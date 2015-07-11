public class Solution {
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1 + 1, index2 + 1] (index1 < index2)
     */
    public int[] twoSum(int[] numbers, int target) {
        // write your code here
        HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
        ArrayList<Integer> cur = new ArrayList<Integer>();
        for (int i = 0; i < numbers.length; i ++) {
            if (numbers[i] * 2 == target) {
                cur.add(i);
            } else {
                hash.put(numbers[i], i + 1);
            }
        }
        int []res = new int[2];
        if (cur.size() >= 2) {
            res[0] = cur.get(0);
            res[1] = cur.get(1);
            return res;
        }
        for (int i = 0; i < numbers.length; i ++) {
            if (hash.containsKey(target - numbers[i])) {
                int temp = hash.get(target - numbers[i]);
                res[0] = Math.min(temp, i + 1);
                res[1] = Math.max(temp, i + 1);
                return res;
            }
        }
        return res;
    }
}
