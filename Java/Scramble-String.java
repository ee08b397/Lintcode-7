public class Solution {
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    public boolean isScramble(String s1, String s2) {
        // Write your code here
        if (s1.length() != s2.length()) return false;
        int []vis = new int[26];
        for (int i = 0; i < s1.length(); i ++) {
            vis[s1.charAt(i) - 'a'] ++;
        }
        for (int i = 0; i < s2.length(); i ++) {
            vis[s2.charAt(i) - 'a'] --;
            if (vis[s2.charAt(i) - 'a'] < 0) return false;
        }
        if (s1.length() <= 3) return true;
        int len = s1.length();
        for (int i = 1; i < len; i ++) {
            if (isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i), s2.substring(i)))
                return true;
            if (isScramble(s1.substring(0, i), s2.substring(len - i)) && isScramble(s1.substring(i), s2.substring(0, len - i)))
                return true;
        }
        return false;
    }
}
