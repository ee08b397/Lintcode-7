public class Solution {
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    public boolean IsOp(String str) {
        if (str.equals("-") || str.equals("+") || str.equals("/") || str.equals("*")) return true;
        return false;
    }
    public int evalRPN(String[] tokens) {
        // Write your code here
        Stack<Integer> stk = new Stack<Integer>();
        for (int i = 0; i < tokens.length; i ++) {
            if (IsOp(tokens[i])) {
                int x = stk.pop(), y = stk.pop();
                if (tokens[i].equals("+")) stk.push(x + y);
                else if (tokens[i].equals("*")) stk.push(x * y);
                else if (tokens[i].equals("-")) stk.push(y - x);
                else stk.push(y / x);
            } else {
                stk.push(Integer.parseInt(tokens[i]));
            }
        }
        return stk.pop();
    }
}
