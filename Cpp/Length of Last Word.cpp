#include <string>

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int pos = s.length() - 1, end;
        while (pos >= 0 && s[pos] == ' ') pos --;
        end = pos;
        while (pos >= 0 && s[pos] != ' ') pos --;
        return end - pos;
    }
};
