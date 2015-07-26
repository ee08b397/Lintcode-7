public class Solution {
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    public boolean isOp(String s) {
        if (s.length() == 1 && !Character.isDigit(s.charAt(0))) return true;
        return false;
    }
    public boolean OpFirst(String s1, String s2) {
        if (s2.equals("/") || s2.equals("*")) return true;
        else if (s2.equals("+") || s2.equals("-")) {
            if (s1.equals("/") || s1.equals("*")) return false;
            else return true;
        } else return false;
    }
    public ArrayList<String> convertToRPN(String[] expression) {
        // write your code here
        ArrayList<String> res = new ArrayList<String>();
        Stack<String> OpStk = new Stack<String>();
        for (int i = 0; i < expression.length; i ++) {
            if (!isOp(expression[i])) {
                res.add(expression[i]);
            } else {
                if (OpStk.isEmpty()) {
                    OpStk.push(expression[i]);
                } else {
                    if (expression[i].equals("(")) OpStk.push(expression[i]);
                    else if (expression[i].equals(")")) {
                        while (!OpStk.peek().equals("(")) {
                            res.add(OpStk.pop());
                        }
                        OpStk.pop();
                    } else {
                        while (!OpStk.isEmpty() && OpFirst(expression[i], OpStk.peek())) {
                           res.add(OpStk.pop());
                        }
                        OpStk.push(expression[i]);
                    }
                }
            }
        }
        while (!OpStk.isEmpty()) {
            res.add(OpStk.pop());
        }
        return res;
    }
}
