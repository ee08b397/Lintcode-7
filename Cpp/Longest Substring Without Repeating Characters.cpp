#include <string>

class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        const int ASCII_MAX = 256;
        int appeared_count[256];
        fill(appeared_count, appeared_count + ASCII_MAX, 0);
        int maxlen = 0, start = 0;
        for (int i = 0; i < s.size(); i ++) {
            char ch = s[i];
            if (appeared_count[ch] == 0) {
                appeared_count[ch] ++;
                maxlen = max(maxlen, i - start + 1);
            } else {
                while (appeared_count[ch] > 0) {
                    appeared_count[s[start]] --;
                    start ++;
                }
                appeared_count[ch] ++;
            }
        }
        return maxlen;
    }
};
