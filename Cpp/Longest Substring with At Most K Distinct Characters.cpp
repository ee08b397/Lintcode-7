#include <string>

class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        if (k <= 0) return 0;
        const int ASCII_MAX = 256;
        int appeared_count[ASCII_MAX];
        fill(appeared_count, appeared_count + ASCII_MAX, 0);
        int maxlen = 0, start = 0, num = 0;
        for (int i = 0; i < s.size(); i ++) {
            char ch = s[i];
            if (appeared_count[ch] == 0) {
                num ++;
            }
            appeared_count[ch] ++;
            if (num <= k) maxlen = max(maxlen, i - start + 1);
            while (num > k) {
                char c = s[start];
                appeared_count[c] --;
                if (appeared_count[c] == 0) num --;
                start ++;
            }
        }
        return maxlen;
    }
};
