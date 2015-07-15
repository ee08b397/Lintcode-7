public class Solution {
    /**
     * @param s Roman representation
     * @return an integer
     */
    public int romanToInt(String s) {
        // Write your code here
        if (s == null || s.length() <= 0) return 0;
        Map<Character, Integer> m = new HashMap<Character, Integer>();
        m.put('I', 1);
        m.put('V', 5);
        m.put('X', 10);
        m.put('L', 50);
        m.put('C', 100);
        m.put('D', 500);
        m.put('M', 1000);
        int res = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (i + 1 < s.length()) {
                if (m.get(s.charAt(i)) < m.get(s.charAt(i + 1))) {
                    res = res - m.get(s.charAt(i));
                } else {
                    res += m.get(s.charAt(i));
                }
            } else {
                res += m.get(s.charAt(i));
            }
        }
        return res;
    }
}
