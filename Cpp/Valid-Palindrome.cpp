#include <string>

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isalphanumeric(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) return true;
        else if (ch >= '0' && ch <= '9') return true;
        else return false;
    }
    bool isequal(char ch1, char ch2) {
        if (ch1 >= 'A' && ch1 <= 'Z') ch1 = 'a' + ch1 - 'A';
        if (ch2 >= 'A' && ch2 <= 'Z') ch2 = 'a' + ch2 - 'A';
        if (ch1 == ch2) return true;
        else return false;
    }
    bool isPalindrome(string& s) {
        // Write your code here
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < right && !isalphanumeric(s[left])) left ++;
            while (left < right && !isalphanumeric(s[right])) right --;
            if (left < right && !isequal(s[left], s[right])) {
                return false;
            } else {
                left ++;
                right --;
            }
        }
        return true;
    }
};
