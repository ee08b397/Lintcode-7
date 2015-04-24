#include <string>
#include <vector>

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        string str;
        if (strs.empty()) return str;
        for (int i = 0; i < strs[0].size(); i ++) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j ++) {
                if (i >= strs[j].size() || strs[j][i] != ch) return str;
            }
            str += ch;
        }
        return str;
    }
};
