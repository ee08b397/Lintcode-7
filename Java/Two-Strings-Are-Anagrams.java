public class Solution {
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    public boolean anagram(String s, String t) {
        // write your code here
        int[] vis = new int[256];
        for (int i = 0; i < s.length(); i ++) {
            vis[s.charAt(i)] ++;
        }
        for (int i = 0; i < t.length(); i ++) {
            if (-- vis[t.charAt(i)] < 0) return false;
        }
        for (int i = 0; i < 256; i ++) {
            if (vis[i] != 0) return false;
        }
        return true;
    }
};