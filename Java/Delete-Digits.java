public class Solution {
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    public String DeleteDigits(String A, int k) {
        // write your code here
        if (A.length() == k) return "";
        Stack<Character> stk = new Stack<Character>();
        int popcount = 0;
        for (int i = 0; i < A.length(); i ++) {
            char c = A.charAt(i);
            if (stk.isEmpty()) {
                stk.push(c);
            } else if (Integer.valueOf(c) >= Integer.valueOf(stk.peek())) {
                stk.push(c);
            } else {
                if (popcount < k) {
                    stk.pop();
                    popcount ++;
                    i --;
                } else {
                    stk.push(c);
                }
            }
        }
        while (popcount < k) {
            stk.pop();
            popcount ++;
        }
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < stk.size(); i ++) {
            sb.append(stk.get(i));
        }
        String res = sb.toString();
        while (res.length() > 1 && res.charAt(0) == '0') {
            res = res.substring(1);
        }
        return res;
    }
}
