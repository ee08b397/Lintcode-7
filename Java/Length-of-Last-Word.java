public class Solution {
    /**
     * @param s A string
     * @return the length of last word
     */
    public int lengthOfLastWord(String s) {
        // Write your code here
        int cur = s.length() - 1;
        while (cur >= 0 && s.charAt(cur) == ' ') cur --;
        int res = 0;
        while (cur >= 0 && s.charAt(cur) != ' ') {
        	res ++;
        	cur --;
        }
        return res;
    }
}
