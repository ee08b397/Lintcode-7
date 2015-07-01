public class Solution {
    /**
     * @param n the nth
     * @return the nth sequence
     */
    public String solve(String s) {
    	String str;
    	int num = 1;
    	char ch = s.charAt(0);
    	for (int i = 1; i < s.length(); i ++) {
    		if (s.charAt(i) != ch) {
    			str += String.valueOf(num);
    			str += ch;
    			ch = s.charAt(i);
    			num = 1;
    		} else {
    			num ++;
    		}
    	}
    	str += String.valueOf(num);
    	str += ch;
    	return str;
    }
    public String countAndSay(int n) {
        // Write your code here
        String s = "1";
        while (n > 1) {
        	s = solve(s);
        }
        return s;
    }
}
