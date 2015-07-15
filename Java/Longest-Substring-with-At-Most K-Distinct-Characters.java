public class Solution {
    /**
     * @param s : A string
     * @return : The length of the longest substring
     *           that contains at most k distinct characters.
     */
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        // write your code here
        int maxlen = 0, left = 0, num = 0;
        int []hash = new int[256];
        for (int i = 0; i < s.length(); i ++) {
            if (hash[s.charAt(i)] == 0) {
                num ++;
            }
            hash[s.charAt(i)] ++;
            while (num > k) {
                hash[s.charAt(left)] --;
                if (hash[s.charAt(left)] == 0) num --;
                left ++;
            }
            maxlen = Math.max(maxlen, i - left + 1);
        }
        return maxlen;
    }
}