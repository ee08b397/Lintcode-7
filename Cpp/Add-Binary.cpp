#include <string>

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        int d = 0, index1 = a.length() - 1, index2 = b.length() - 1;
        string str = "";
        char ch;
        while (index1 >= 0 && index2 >= 0) {
            int temp = a[index1] - '0' + b[index2] - '0' + d;
            ch = temp % 2 + '0';
            d = temp / 2;
            str += ch;
            index1 --;
            index2 --;
        }
        while (index1 >= 0) {
            int temp = a[index1] - '0' + d;
            ch = temp % 2 + '0';
            d = temp / 2;
            str += ch;
            index1 --;
        }
        while (index2 >= 0) {
            int temp = b[index2] - '0' + d;
            ch = temp % 2 + '0';
            d = temp / 2;
            str += ch;
            index2 --;
        }
        if (d) {
            ch = d + '0';
            str += ch;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
