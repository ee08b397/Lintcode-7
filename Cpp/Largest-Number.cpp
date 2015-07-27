class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    static bool cmp(string str1, string str2) {
        return str1 + str2 > str2 + str1;
    }
    string int2str(int num) {
        string str = "";
        if (num == 0) return "0";
        stack<char> st;
        while (num != 0) {
            char ch = num % 10 + '0';
            num = num / 10;
            st.push(ch);
        }
        while (!st.empty()) {
            str += st.top();
            st.pop();
        }
        return str;
    }
    string largestNumber(vector<int> &num) {
        // write your code here
        vector<string> vec;
        for (int i = 0; i < num.size(); i ++) {
            vec.push_back(int2str(num[i]));
        }
        sort(vec.begin(), vec.end(), cmp);
        string str = "";
        int tag = 0;
        for (int i = 0; i < vec.size(); i ++) {
            if (vec[i] != "0") {
                tag = 1;
                str += vec[i];
            } else if (tag == 1 ) {
                str += vec[i];
            }
        }
        if (str == "") return "0";
        else return str;
    }
};
