public class Solution {
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    public boolean ok(String s, int left, int right) {
        if (left == right) return true;
        while (left < right) {
            if (s.charAt(left ++) != s.charAt(right -- )) return false;
        }
        return true;
    }
    public void solve(int start, String s, List<List<String>> res, List<String> cur) {
        if (start >= s.length()) {
            res.add(new LinkedList<String>(cur));
            return;
        }
        for (int i = start; i < s.length(); i ++) {
            if (ok(s, start, i)) {
                cur.add(s.substring(start, i + 1));
                solve(i + 1, s, res, cur);
                cur.remove(cur.size() - 1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        // write your code here
        List<List<String>> res = new LinkedList<List<String>>();
        List<String> cur = new LinkedList<String>();
        solve(0, s, res, cur);
        return res;
    }
}
