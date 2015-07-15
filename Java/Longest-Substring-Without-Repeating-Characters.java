public class Solution {
    /**
     * @param s: a string
     * @return: an integer
     */
    public int lengthOfLongestSubstring(String s) {
        // write your code here
        int maxlen = 0, left = 0;
        int []hash = new int[256];
        for (int i = 0; i < s.length(); i ++) {
            hash[s.charAt(i)] ++;
            while (hash[s.charAt(i)] > 1) {
                hash[s.charAt(left)] --;
                left ++;
            }
            maxlen = Math.max(maxlen, i - left + 1);
        }
        return maxlen;
    }
}