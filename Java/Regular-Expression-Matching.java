public class Solution {
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    public boolean isMatch(String s, String p) {
        // write your code here
        int lens = s.length(), lenp = p.length();
        boolean[][] match = new boolean[lens + 1][lenp + 1];
        match[0][0] = true;
        for (int i = 0; i < lenp; i ++) {
            if (p.charAt(i) == '*' && i > 0) match[0][i + 1] = match[0][i - 1];
        }
        for (int i = 0; i < s.length(); i ++) {
            for (int j = 0; j < p.length(); j ++) {
                if (p.charAt(j) != '*' && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.'))
                    match[i + 1][j + 1] = match[i][j];
                else if (p.charAt(j) == '*') {
                    if (j > 0 && match[i + 1][j - 1] || match[i + 1][j]) match[i + 1][j + 1] = true;
                    else if (j > 0 && match[i][j + 1] && (s.charAt(i) == p.charAt(j - 1) || p.charAt(j - 1) == '.'))
                        match[i + 1][j + 1] = true;
                }
            }
        }
        return match[lens][lenp];
    }
}