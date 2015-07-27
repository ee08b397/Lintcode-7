#include <string>
#include <vector>
#include <stack>


class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        // write your code here
        stack<int> IntStack;
        stack<string> OpStack;
        int cur = 0;
        while (cur < expression.size()) {
            string str = expression[cur];
            if (isOp(str)) {
                if (str == "(") {
                    OpStack.push(str);
                } else if (str == ")") {
                    while (OpStack.top() != "(") {
                        int temp1 = IntStack.top();
                        IntStack.pop();
                        int temp2 = IntStack.top();
                        IntStack.pop();
                        IntStack.push(cal(OpStack.top(), temp1, temp2));
                        OpStack.pop();
                    }
                    OpStack.pop();
                } else {
                    while (!OpStack.empty() && precedence(str, OpStack.top())) {
                        int temp1 = IntStack.top();
                        IntStack.pop();
                        int temp2 = IntStack.top();
                        IntStack.pop();
                        IntStack.push(cal(OpStack.top(), temp1, temp2));
                        OpStack.pop();
                    }
                    OpStack.push(str);
                }
            } else {
                IntStack.push(stoi(str));
            }
            cur ++;
        }
        while (!OpStack.empty()) {
            int temp1 = IntStack.top();
            IntStack.pop();
            int temp2 = IntStack.top();
            IntStack.pop();
            IntStack.push(cal(OpStack.top(), temp1, temp2));
            OpStack.pop();
        }
        if (IntStack.empty()) return 0;
        else return IntStack.top();
    }

    int cal(string str, int a, int b) {
        if (str == "+") return a + b;
        else if (str == "-") return b - a;
        else if (str == "*") return a * b;
        else return b / a;
    }
    bool isOp(string str) {
        if (str == "+" || str == "-" || str == "*" || str == "/"
            || str == "(" || str == ")") return true;
        else return false;
    }
    bool precedence(string a, string b) {
        if (b == "*" || b == "/") {
            return true;
        }
        if (b == "+" || b == "-") {
            if (a == "*" || a == "/") return false;
            else return true;
        }
        return false;
    }
};
