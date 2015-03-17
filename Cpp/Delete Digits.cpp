class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        stack <int> st;
        int popcount = 0;
        for (int i = 0; i < A.size(); i ++) {
            int num = A[i] - '0';
            if (st.empty()) {
                st.push(num);
            } else if (num >= st.top()) {
                st.push(num);
            } else {
                if (popcount < k) {
                    st.pop();
                    i--;
                    popcount ++;
                } else {
                    st.push(num);
                }
            }
        }
        while (popcount < k) {
            popcount ++;
            st.pop();
        }
        string str = "";
        while (!st.empty()) {
            char ch = '0' + st.top();
            str += ch;
            st.pop();
        }
        reverse(str.begin(), str.end());
        while (str.size() > 1 && str[0] == '0') {
            str = str.substr(1, str.size()-1);
        }
        return str;
    }
};
