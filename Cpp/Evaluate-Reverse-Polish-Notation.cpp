#include <string>
#include <stack>
#include <vector>

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        stack<int> st;
        for (int i = 0; i < tokens.size(); i ++) {
            if (tokens[i] == "+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x + y);
            } else if (tokens[i] == "-") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y - x);
            } else if (tokens[i] == "*") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y * x);
            } else if (tokens[i] == "/") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y / x);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
