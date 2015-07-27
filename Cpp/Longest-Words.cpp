#include <vector>
#include <string>

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> vec;
        if (dictionary.empty()) return vec;
        vec.push_back(dictionary[0]);
        int maxlen = dictionary[0].length(), len = dictionary.size();
        for (int i = 1; i < len; i ++) {
            if (dictionary[i].length() > maxlen) {
                maxlen = dictionary[i].length();
                vec.clear();
                vec.push_back(dictionary[i]);
            } else if (maxlen == dictionary[i].length()) {
                vec.push_back(dictionary[i]);
            }
        }
        return vec;
    }
};
