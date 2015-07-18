public class Solution {
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    public String longestCommonPrefix(String[] strs) {
        // write your code here
        if (strs == null || strs.length == 0) return "";
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < strs[0].length(); i ++) {
            char temp = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j ++) {
                if (i >= strs[j].length() || temp != strs[j].charAt(i)) return sb.toString();
            }
            sb.append(temp);
        }
        return sb.toString();
    }
}