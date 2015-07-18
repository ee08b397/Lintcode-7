public class Solution {
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    public String minWindow(String source, String target) {
        // write your code
        int[] hash_s = new int[256];
        int[] hash_t = new int[256];
        int start = 0, num = 0, pos = 0, minlen = Integer.MAX_VALUE, cur = 0;
        for (int i = 0; i < target.length(); i ++) {
            if (hash_t[target.charAt(i)] == 0) num ++;
            hash_t[target.charAt(i)] ++;
        }
        for (int i = 0; i < source.length(); i ++) {
            hash_s[source.charAt(i)] ++;
            if (hash_s[source.charAt(i)] == hash_t[source.charAt(i)]) cur ++;
            while (cur >= num) {
                if (minlen > i - pos + 1) {
                    start = pos;
                    minlen = i - pos + 1;
                }
                if (hash_s[source.charAt(pos)] == hash_t[source.charAt(pos)]) {
                    cur --;
                }
                hash_s[source.charAt(pos)] --;
                pos ++;
            }
        }
        if (minlen == Integer.MAX_VALUE) return "";
        return source.substring(start, start + minlen);
    }
}