#include <string>
//#include <stack>
#include <vector>

class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        vector<string> vec;
        vector<string> stk;
        string str;
        for (int i = 0; i < path.length(); i ++) {
            if (path[i] == '/') {
                if (str != "") vec.push_back(str);
                str = "";
            } else {
                str += path[i];
            }
        }
        if (str != "") vec.push_back(str);
        for (int i = 0; i < vec.size(); i ++) {
            if (vec[i] == "..") {
                if (!stk.empty()) stk.pop_back();
            } else if (vec[i] != ".") {
                stk.push_back(vec[i]);
            }
        }
        if (stk.empty()) return "/";
        string s;
        for (int i = 0; i < stk.size(); i ++) {
            s += "/";
            s += stk[i];
        }
        return s;
    }
};
