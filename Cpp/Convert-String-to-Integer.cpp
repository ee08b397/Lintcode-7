#include <string>

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        int num = 0, sign = 1, len = str.size(), i = 0;
        while (str[i] == ' ' && i < len) i++;
        if (str[i] == '+') i++;
        else if (str[i] == '-') {
            i++;
            sign = -1;
        }
        for (; i < len; i++) {
            if (str[i] < '0' || str[i] > '9') break;
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0' >= INT_MAX % 10))) {
                if (sign == -1) return INT_MIN;
                else return INT_MAX;
            }
            num = num * 10 + str[i] - '0';
        }
        return num * sign;
    }
};
