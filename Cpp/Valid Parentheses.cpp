#include <stack>

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<char> stk;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) return false;
                if (s[i] == ')') if (stk.top() != '(') return false;
                else if (s[i] == ']') if (stk.top() != '[') return false;
                else if (s[i] == '}') if (stk.top() != '{') return false;
                stk.pop();
            }
        }
        if (stk.empty()) return true;
        else return false;
    }
};
