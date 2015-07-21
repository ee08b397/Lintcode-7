public class Solution {
    /**
     * @param path the original path
     * @return the simplified path
     */
    public String simplifyPath(String path) {
        // Write your code here
        Stack<String> stk = new Stack<String>();
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < path.length(); i ++) {
            if (path.charAt(i) == '/') {
                if (sb.length() > 0) {
                    String temp = sb.toString();
                    if (temp.equals("..")) {
                        if (!stk.isEmpty()) stk.pop();
                    } else if (!temp.equals(".")) {
                        stk.push(temp);
                    }
                }
                sb = new StringBuffer();
            } else {
                sb.append(path.charAt(i));
            }
        }
        if (sb.length() > 0) {
            String temp = sb.toString();
            if (temp.equals("..")) {
                if (!stk.isEmpty()) stk.pop();
            } else if (!temp.equals(".")) {
                stk.push(temp);
            }
        }
        sb = new StringBuffer();
        if (stk.isEmpty()) return "/";
        for (int i = 0; i < stk.size(); i ++) {
            sb.append("/");
            sb.append(stk.get(i));
        }
        return sb.toString();
    }
}