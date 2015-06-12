#include <vector>
#include <stack>
#include <string>


class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    bool isOp(string str) {
        if (str == "+" || str == "-" || str == "*" || str == "/"
            || str == "(" || str == ")") return true;
        else return false;
    }
    int precedence(string x) {
        if (x == "(") {
            return 0;
        } else if (x == "+" || x == "-") {
            return 1;
        } else if (x == "*" || x == "/") {
            return 2;
        }
        return 3;
    }
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        vector<string> RPN;
        int cur = 0;
        stack<string> OpStack;
        while (cur < expression.size()) {
            string str = expression[cur++];
            if (isOp(str)) {
                if (str == "(") {
                    OpStack.push(str);
                } else if (str == ")") {
                    while (OpStack.top() != "(") {
                        RPN.push_back(OpStack.top());
                        OpStack.pop();
                    }
                    OpStack.pop();
                } else {
                    while (!OpStack.empty() && precedence(OpStack.top()) >= precedence(str)) {
                        RPN.push_back(OpStack.top());
                        OpStack.pop();
                    }
                    OpStack.push(str);
                }
            } else {
                RPN.push_back(str);
            }
        }
        while (!OpStack.empty()) {
            RPN.push_back(OpStack.top());
            OpStack.pop();
        }
        return RPN;
    }
};
