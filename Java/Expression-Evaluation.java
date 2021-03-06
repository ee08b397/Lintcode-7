public class Solution {
    /**
     * @param expression: an array of strings;
     * @return: an integer
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
    public int IntCal(int x, int y, String Op) {
        if (Op.equals("+")) return x + y;
        else if (Op.equals("-")) return y - x;
        else if (Op.equals("*")) return x * y;
        else return y / x;
    }
    public int evaluateExpression(String[] expression) {
        // write your code here
        Stack<String> OpStk = new Stack<String>();
        Stack<Integer> IntStk = new Stack<Integer>();
        for (int i = 0; i < expression.length; i ++) {
            if (!isOp(expression[i])) {
                IntStk.push(Integer.parseInt(expression[i]));
            } else {
                if (OpStk.isEmpty()) {
                    OpStk.push(expression[i]);
                } else {
                    if (expression[i].equals("(")) OpStk.push(expression[i]);
                    else if (expression[i].equals(")")) {
                        while (!OpStk.peek().equals("(")) {
                            int x = IntStk.pop(), y = IntStk.pop();
                            IntStk.push(IntCal(x, y, OpStk.pop()));
                        }
                        OpStk.pop();
                    } else {
                        while (!OpStk.isEmpty() && OpFirst(expression[i], OpStk.peek())) {
                            int x = IntStk.pop(), y = IntStk.pop();
                            IntStk.push(IntCal(x, y, OpStk.pop()));
                        }
                        OpStk.push(expression[i]);
                    }
                }
            }
        }
        while (!OpStk.isEmpty()) {
            int x = IntStk.pop(), y = IntStk.pop();
            IntStk.push(IntCal(x, y, OpStk.pop()));
        }
        if (IntStk.isEmpty()) return 0;
        return IntStk.peek();
    }
};
