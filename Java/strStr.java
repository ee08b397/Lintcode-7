class Solution {
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    public int strStr(String source, String target) {
        //write your code here
        if (source == null || target == null) return -1;
        int len1 = source.length(), len2 = target.length();
        for (int i = 0; i + len2 - 1 < len1; i ++) {
            int cur = 0, cnt = i;
            while (cur < len2 && source.charAt(cnt) == target.charAt(cur)) {
                cnt ++;
                cur ++;
            }
            if (cur == len2) return i;
        }
        return -1;
    }
}
