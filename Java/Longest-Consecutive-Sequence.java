public class Solution {
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    public int longestConsecutive(int[] num) {
        // write you code here
        HashSet<Integer> hash = new HashSet<Integer>();
        for (int i = 0; i < num.length; i ++) {
            hash.add(num[i]);
        }
        int maxlen = 0;
        for (int i = 0; i < num.length; i ++) {
            if (hash.contains(num[i])) {
                int temp = num[i] + 1, len = 1;
                while (hash.contains(temp)) {
                    hash.remove(temp);
                    temp ++;
                    len ++;
                }
                temp = num[i] - 1;
                while (hash.contains(temp)) {
                    hash.remove(temp);
                    temp --;
                    len ++;
                }
                maxlen = Math.max(len, maxlen);
            }
        }
        return maxlen;
    }
}

