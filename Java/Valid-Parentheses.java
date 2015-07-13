public class Solution {
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    public boolean isValidParentheses(String s) {
        // Write your code here
        Stack<Character> stk = new Stack<Character>();
        for (int i = 0; i < s.length(); i ++) {
            char temp = s.charAt(i);
            if (temp == '(' || temp == '[' || temp == '{') {
                stk.push(temp);
            } else {
                if (stk.empty()) return false;
                if (temp == ')') {
                    if (stk.peek() == '(') {
                        stk.pop();
                    } else {
                        return false;
                    }
                } else if (temp == ']') {
                    if (stk.peek() == '[') {
                        stk.pop();
                    } else {
                        return false;
                    }
                } else if (temp == '}') {
                    if (stk.peek() == '{') {
                        stk.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        if (stk.empty()) return true;
        else return false;
    }
}
