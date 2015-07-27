class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        string str = "";
        stack<string> st;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] != ' ') str += s[i];
            else {
                if (str != "") {
                    st.push(str);
                    str = "";
                }
            }
        }
        if (str != "") st.push(str);
        str = "";
        if (!st.empty()) {
            str += st.top();
            st.pop();
        }
        while (!st.empty()) {
            str += " ";
            str += st.top();
            st.pop();
        }
    }
};
